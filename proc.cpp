#include "proc.h"

ProcMeta::ProcMeta(std::string cmdLine, size_t pid) {
    this->procCmd = cmdLine;
    this->pid = pid;
}
const std::string& ProcMeta::GetProcCmd() {
    return this->procCmd;
}
const size_t ProcMeta::GetPID() {
    return this->pid;
}