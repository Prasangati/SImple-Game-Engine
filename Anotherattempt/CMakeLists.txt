cmake_minimum_required(VERSION 3.28)
project(Anotherattempt)

set(CMAKE_CXX_STANDARD 20)

add_executable(Anotherattempt main.cpp
        SimOS.cpp
        SimOS.h
        DiskManager.cpp
        DiskManager.h
        utility.h)
