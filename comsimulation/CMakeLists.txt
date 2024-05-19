# Minimum CMake version required
cmake_minimum_required(VERSION 3.27)

# Project name
project(comsimulation)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable and include source files
add_executable(comsimulation
        main.cpp
        CPUManager.cpp
        DiskManager.cpp
        MemoryManager.cpp
        ProcessManager.cpp
)

# Add include directories if needed
target_include_directories(comsimulation PRIVATE ${CMAKE_SOURCE_DIR}/include)

# If you have any specific libraries to link, you can add them here
# target_link_libraries(SimOS PRIVATE some_library)
