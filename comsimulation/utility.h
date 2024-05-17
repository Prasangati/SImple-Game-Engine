//
// Created by Prasanga Tiwari on 5/17/24.
//

#ifndef COMSIMULATION_UTILITY_H
#define COMSIMULATION_UTILITY_H
#include <string>
#include <vector>

struct FileReadRequest
{
    int  PID{0};
    std::string fileName{""};
};

struct MemoryItem
{
    unsigned long long pageNumber;
    unsigned long long frameNumber;
    int PID; // PID of the process using this frame of memory
};

using MemoryUsage = std::vector<MemoryItem>;

constexpr int NO_PROCESS{ 0 };
#endif //COMSIMULATION_UTILITY_H
