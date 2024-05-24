//
// Created by Prasanga Tiwari on 5/17/24.
//

#ifndef COMSIMULATION_MEMORYMANAGER_H
#define COMSIMULATION_MEMORYMANAGER_H


#include "utility.h"
#include <algorithm>

class MemoryManager {
public:
    MemoryManager(unsigned long long amountOfRAM, unsigned int pageSize);
    void accessMemory(int pid, unsigned long long address);
    void releaseMemory(int pid);
    MemoryUsage getMemoryUsage() const;

private:
    unsigned long long amountOfRAM;
    unsigned int pageSize;
    MemoryUsage memoryUsage;
};





#endif //COMSIMULATION_MEMORYMANAGER_H
