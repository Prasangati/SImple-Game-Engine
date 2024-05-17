// Your Name

#ifndef SIMOS_H
#define SIMOS_H




#include "CPUManager.h"
#include "MemoryManager.h"
#include "DiskManager.h"
#include "ProcessManager.h"
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
    CPUManager cpu;
    MemoryManager memoryManager;
    DiskManager diskManager;
    ProcessManager processManager;
};







#endif // SIMOS_H

