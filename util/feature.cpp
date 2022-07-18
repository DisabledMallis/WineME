#include "feature.h"
#include <imgui.h>

Feature::Feature(){

}
Feature::~Feature() {
    
}
void Feature::Render() {
    ImGui::Begin("Uh-oh");
    ImGui::Text("If you're reading this, something probably went wrong. If you can reproduce this message, consider making an issue on GitHub.");
    ImGui::End();
}