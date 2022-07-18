#include "procFinder.h"
#include <mutex>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

std::mutex metaLock;
static std::vector<ProcMeta> procMetaHolder;

const std::vector<ProcMeta>& ProcFinder::GetAllProcs() {
    metaLock.lock();
    metaLock.unlock();
    return procMetaHolder;
}

const std::vector<ProcMeta>& ProcFinder::UpdateProcList() {
    metaLock.lock();
    procMetaHolder.clear();
    if(fs::exists("/proc")) {
        //Update process list
        printf("Updating proc list");
        for(auto const& dir : fs::directory_iterator("/proc")) {
            //printf("%s", dir.path().filename().string().c_str());
            fs::path cmdLinePath = dir / fs::path("cmdline");
            std::ifstream cmdLineStream(cmdLinePath);
            std::string cmdLine(std::istreambuf_iterator<char>{cmdLineStream}, {});
            std::string pidStr = dir.path().filename().string();
            printf("%s", pidStr.c_str());
            try {
                size_t pid = stoi(pidStr);
                procMetaHolder.emplace_back(cmdLine, pid);
            }
            catch(std::exception& ex) {
                //Not all dirs in /proc are actually procids, and may contain things other than numbers.
                //we don't really care about these though
            }
        }
    } else {
        printf("No proc folder in root?");
    }
    metaLock.unlock();
    return GetAllProcs();
}