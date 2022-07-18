#include "proc.h"

ProcMeta::ProcMeta(std::string cmdLine, size_t pid) {
    this->procCmd = cmdLine;
    this->pid = pid;
    //Calc length that will be printed
    size_t lenReq = snprintf(0, 0, "%x (%d) %s", pid, pid, cmdLine.c_str());
    //Allocate on the stack
    char* text = (char*)alloca(lenReq+1);
    //Format into that buffer
    sprintf(text, "%x (%d) %s", pid, pid, cmdLine.c_str());
    //Store the string into the object for later
    this->formatted = std::string(text);
}
const std::string& ProcMeta::GetProcCmd() {
    return this->procCmd;
}
const size_t ProcMeta::GetPID() {
    return this->pid;
}
const std::string& ProcMeta::GetFormatted() {
    return this->formatted;
}