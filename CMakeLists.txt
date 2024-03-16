cmake_minimum_required(VERSION 3.27)
project(Prasanga_GAME VERSION 1.0 DESCRIPTION "Dynamic Library that is used by the game")

set(CMAKE_CXX_STANDARD 20) # Using C++20 for this project
set(CMAKE_CXX_STANDARD_REQUIRED True)
# Optionally set global compiler options or definitions here
# add_compile_options(-Wall -Wextra -pedantic) # Example for GCC/Clang
add_definitions(-DUltimate_DEBUG=2)
# Include subprojects or subdirectories
add_subdirectory(Ultimate_Game_Engine)
add_subdirectory(S24_Prasanga_Tiwari)

