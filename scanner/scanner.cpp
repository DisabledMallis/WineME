#include "scanner.h"
#include <imgui.h>

Scanner::Scanner(ProcMeta target) : Feature::Feature(), target(target) {
    //Calc length that will be printed
    size_t lenReq = snprintf(0, 0, "Scanner - PID %x (%d)", target.GetPID(), target.GetPID());
    //Allocate on the stack
    char* text = (char*)alloca(lenReq+1);
    //Format into that buffer
    sprintf(text, "Scanner - PID %x (%d)", target.GetPID(), target.GetPID());
    this->title = std::string(text);
}
Scanner::~Scanner() {
    
}
void Scanner::Render() {
    ImGui::Begin(this->title.c_str(), &this->pleaseDelete);
    ImGui::End();
}