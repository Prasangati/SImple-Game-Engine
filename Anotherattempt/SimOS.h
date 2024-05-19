//
// Created by Prasanga Tiwari on 5/18/24.
//

#ifndef SIMOS_H
#define SIMOS_H
#include <vector>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include "DiskManager.h"
#include "utility.h"


class SimOS {
public:
    SimOS(int numberOfDisks, unsigned long long amountOfRAM, unsigned int pageSize);

    void NewProcess();
    void SimFork();
    void SimExit();
    void SimWait();
    void TimerInterrupt();
    void DiskReadRequest(int diskNumber, std::string fileName);
    void DiskJobCompleted(int diskNumber);
    void AccessMemoryAddress(unsigned long long address);
    int GetCPU();
    std::deque<int> GetReadyQueue();
    MemoryUsage GetMemory();
    FileReadRequest GetDisk(int diskNumber);
    std::deque<FileReadRequest> GetDiskQueue(int diskNumber);

private:
    int numberOfDisks;
    unsigned long long amountOfRAM;
    unsigned int pageSize;
    int nextPID;
    int currentCPU;
    std::deque<int> readyQueue;
    MemoryUsage memory;
    DiskManager diskManager;

    std::unordered_map<int, std::unordered_set<int>> children; // Parent to children mapping
    std::unordered_map<int, int> parent; // Child to parent mapping
    std::unordered_set<int> zombies; // Set of zombie processes

    void releaseMemory(int PID);
    void terminateProcess(int PID);
    void handleOrphans(int PID);
    void printReadyQueue(); // Added method declaration
};
#endif // SIMOS_H
