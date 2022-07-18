#include "procFinder.h"
#include <mutex>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

std::mutex metaLock;
static std::vector<ProcMeta> procMetaHolder;

const std::vector<ProcMeta>& ProcFinder::GetAllProcs() {
    const std::lock_guard<std::mutex> lock(metaLock);
    return procMetaHolder;
}

const std::vector<ProcMeta>& ProcFinder::UpdateProcList() {
    const std::lock_guard<std::mutex> lock(metaLock);
    procMetaHolder.clear();
    if(fs::exists("/proc")) {
        //Update process list
        printf("Updating proc list\n");
        for(auto const& dir : fs::directory_iterator("/proc")) {
            if(!dir.is_directory())
                continue;
            try {
                std::string pidStr = dir.path().filename().string();
                size_t pid = stoi(pidStr);

                fs::path cmdLinePath = dir / fs::path("cmdline");
                std::ifstream cmdLineStream(cmdLinePath);
                std::string cmdLine(std::istreambuf_iterator<char>{cmdLineStream}, {});

                printf("%s\n", pidStr.c_str());
                procMetaHolder.emplace_back(cmdLine, pid);
            }
            catch(std::exception& ex) {
                //Not all dirs in /proc are actually procids, and may contain things other than numbers.
                //we don't really care about these though
                printf("Error reading proc: %s\n", ex.what());
            }
        }
    } else {
        printf("No proc folder in root?");
    }
    return procMetaHolder;
}

void ProcFinder::ForEachProc(std::function<void(ProcMeta&)> func) {
    const std::lock_guard<std::mutex> lock(metaLock);
    for(ProcMeta& meta : procMetaHolder) {
        func(meta);
    }
}