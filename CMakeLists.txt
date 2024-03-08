cmake_minimum_required(VERSION 3.27)
project(YourProjectName VERSION 1.0 DESCRIPTION "Your Project Description")

set(CMAKE_CXX_STANDARD 20) # Using C++20 for this project

# Optionally set global compiler options or definitions here
# add_compile_options(-Wall -Wextra -pedantic) # Example for GCC/Clang

# Include subprojects or subdirectories
add_subdirectory(Sun)
add_subdirectory(S24_Prasanga_Tiwari)

