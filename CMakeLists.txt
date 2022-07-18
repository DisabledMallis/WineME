cmake_minimum_required(VERSION 3.20)
project(WineMem VERSION 1.0 LANGUAGES CXX C)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_BUILD_TYPE Debug)

add_executable(WineMem)
target_sources(WineMem PRIVATE
    "main.cpp"
    "proc.cpp"
    "procFinder.cpp"
    "worker.cpp"
)

find_package(SDL2 REQUIRED)
include_directories(WineMem ${SDL2_INCLUDE_DIRS})

add_library(ImGui STATIC)
target_sources(ImGui PRIVATE
    "${CMAKE_CURRENT_LIST_DIR}/imgui/backends/imgui_impl_sdlrenderer.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/imgui/backends/imgui_impl_sdl.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/imgui/imgui.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/imgui/imgui_demo.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/imgui/imgui_draw.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/imgui/imgui_tables.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/imgui/imgui_widgets.cpp"
)
target_include_directories(ImGui PUBLIC
    "${CMAKE_CURRENT_LIST_DIR}/imgui"
    "${CMAKE_CURRENT_LIST_DIR}/imgui/backends"
)

target_link_libraries(WineMem PRIVATE ${SDL2_LIBRARIES} ImGui)