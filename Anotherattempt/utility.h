//
// Created by Prasanga Tiwari on 5/18/24.
//

#ifndef ANOTHERATTEMPT_UTILITY_H
#define ANOTHERATTEMPT_UTILITY_H

#include <string>
#include <vector>
#include <deque>

struct FileReadRequest {
    int PID{0};
    std::string fileName{""};
};

struct MemoryItem {
    unsigned long long pageNumber;
    unsigned long long frameNumber;
    int PID; // PID of the process using this frame of memory
};

using MemoryUsage = std::vector<MemoryItem>;

constexpr int NO_PROCESS{ 0 };



#endif //ANOTHERATTEMPT_UTILITY_H
