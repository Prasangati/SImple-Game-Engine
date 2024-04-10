cmake_minimum_required(VERSION 3.27)
project(Prasanga_GAME VERSION 1.0 DESCRIPTION "Dynamic Library that is used by the game")

set(CMAKE_CXX_STANDARD 20) # Using C++20 for this project
set(CMAKE_CXX_STANDARD_REQUIRED True)
# Optionally set global compiler options or definitions here
# Include subprojects or subdirectories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(glfw)


add_subdirectory(Ultimate_Game_Engine)
add_subdirectory(S24_Prasanga_Tiwari)

set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT S24_Prasanga_Tiwari_App)
