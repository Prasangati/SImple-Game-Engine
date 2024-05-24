//
// Created by Prasanga Tiwari on 5/17/24.
//

#include "MemoryManager.h"

MemoryManager::MemoryManager(unsigned long long amountOfRAM, unsigned int pageSize)
        : amountOfRAM(amountOfRAM), pageSize(pageSize) {}

void MemoryManager::accessMemory(int pid, unsigned long long address) {
    unsigned long long pageNumber = address / pageSize;
    auto it = std::find_if(memoryUsage.begin(), memoryUsage.end(),
                           [pageNumber, pid](const MemoryItem& item) {
                               return item.pageNumber == pageNumber && item.PID == pid;
                           });

    if (it == memoryUsage.end()) {
        MemoryItem newItem{pageNumber, memoryUsage.size(), pid};
        memoryUsage.push_back(newItem);
    } else {
        MemoryItem updatedItem = *it;
        memoryUsage.erase(it);
        memoryUsage.push_back(updatedItem);
    }
}

void MemoryManager::releaseMemory(int pid) {
    memoryUsage.erase(std::remove_if(memoryUsage.begin(), memoryUsage.end(),
                                     [pid](const MemoryItem& item) { return item.PID == pid; }),
                      memoryUsage.end());
}

MemoryUsage MemoryManager::getMemoryUsage() const {
    return memoryUsage;
}



