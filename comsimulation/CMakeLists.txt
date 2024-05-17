cmake_minimum_required(VERSION 3.28)
project(comsimulation)

set(CMAKE_CXX_STANDARD 20)

add_executable(comsimulation
        SimOS.cpp
        SimOS.h
        CPUManager.cpp
        CPUManager.h
        MemoryManager.cpp
        MemoryManager.h
        DiskManager.cpp
        DiskManager.h
        utility.h
        ProcessManager.cpp
        ProcessManager.h
)
