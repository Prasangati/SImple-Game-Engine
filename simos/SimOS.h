//
// Created by Prasanga Tiwari on 5/19/24.
//

#ifndef SIMOS_H
#define SIMOS_H

#include <vector>
#include <deque>
#include <string>
#include <stdexcept>
#include <unordered_map>

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

constexpr int NO_PROCESS{0};

class SimOS {
public:
    SimOS(int numberOfDisks, unsigned long long amountOfRAM, unsigned int pageSize);

    void NewProcess();
    void SimFork();
    void SimExit();
    void reassignCPU();
    void SimWait();
    void TimerInterrupt();
    void DiskReadRequest(int diskNumber, const std::string& fileName);
    void DiskJobCompleted(int diskNumber);
    void AccessMemoryAddress(unsigned long long address);
    int GetCPU() const;
    std::deque<int> GetReadyQueue() const;
    MemoryUsage GetMemory() const;
    FileReadRequest GetDisk(int diskNumber) const;
    std::deque<FileReadRequest> GetDiskQueue(int diskNumber) const;

private:
    int numberOfDisks;
    unsigned long long amountOfRAM;
    unsigned int pageSize;

    int currentPID;
    int currentCPUProcess;

    std::deque<int> readyQueue;
    std::unordered_map<int, std::deque<int>> processChildren;
    std::unordered_map<int, int> processParent;
    std::unordered_map<int, bool> processWaiting;
    std::unordered_map<int, bool> zombieProcesses;

    std::vector<FileReadRequest> disks;
    std::vector<std::deque<FileReadRequest>> diskQueues;

    std::unordered_map<int, std::vector<unsigned long long>> processPages;
    MemoryUsage memory;
    std::deque<unsigned long long> lruPages;

    void terminateProcess(int pid);
};

#endif // SIMOS_H
