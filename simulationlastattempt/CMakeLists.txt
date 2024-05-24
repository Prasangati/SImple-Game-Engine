cmake_minimum_required(VERSION 3.28)
project(simulationlastattempt)

set(CMAKE_CXX_STANDARD 17)

add_executable(simulationlastattempt main.cpp
        CPUManager.cpp
        DiskManager.cpp
        MemoryManager.cpp
        ProcessManager.cpp
        SimOS.cpp)
