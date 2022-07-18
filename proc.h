#pragma once

#include <string>

class ProcMeta {
    std::string procCmd;
    size_t pid;
public:
    ProcMeta(std::string, size_t);
    const std::string& GetProcCmd();
    const size_t GetPID();
};