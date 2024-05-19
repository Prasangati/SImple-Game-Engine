//
// Created by Prasanga Tiwari on 5/18/24.
//

#include "SimOS.h"
#include <algorithm>
#include <iostream>


SimOS::SimOS(int numberOfDisks, unsigned long long amountOfRAM, unsigned int pageSize)
        : numberOfDisks(numberOfDisks), amountOfRAM(amountOfRAM), pageSize(pageSize), nextPID(1), currentCPU(NO_PROCESS),
          diskManager(numberOfDisks) {}

void SimOS::NewProcess() {
    std::cout << "NewProcess: Adding PID " << nextPID << " to readyQueue." << std::endl;
    readyQueue.push_back(nextPID++);
    printReadyQueue();
    if (currentCPU == NO_PROCESS) {
        currentCPU = readyQueue.front();
        readyQueue.pop_front();
        std::cout << "NewProcess: Setting currentCPU to PID " << currentCPU << std::endl;
        printReadyQueue();
    }
}

void SimOS::SimFork() {
    if (currentCPU == NO_PROCESS) throw std::logic_error("SimFork: CPU is idle.");
    int childPID = nextPID++;
    children[currentCPU].insert(childPID);
    parent[childPID] = currentCPU;
    readyQueue.push_back(childPID);
    std::cout << "SimFork: Forked process with PID " << childPID << " from PID " << currentCPU << std::endl;
    printReadyQueue();
}

void SimOS::SimExit() {
    if (currentCPU == NO_PROCESS) throw std::logic_error("SimExit: CPU is idle.");
    int exitingPID = currentCPU;
    std::cout << "SimExit: Terminating process with PID " << exitingPID << std::endl;
    releaseMemory(exitingPID);
    terminateProcess(exitingPID);
    handleOrphans(exitingPID);

    currentCPU = readyQueue.empty() ? NO_PROCESS : readyQueue.front();
    if (currentCPU != NO_PROCESS) readyQueue.pop_front();
    std::cout << "SimExit: New currentCPU is PID " << currentCPU << std::endl;
    printReadyQueue();
}

void SimOS::SimWait() {
    if (currentCPU == NO_PROCESS) throw std::logic_error("SimWait: CPU is idle.");
    int parentPID = currentCPU;
    auto it = std::find_if(zombies.begin(), zombies.end(), [parentPID, this](int pid) { return parent[pid] == parentPID; });

    if (it != zombies.end()) {
        zombies.erase(it);
        std::cout << "SimWait: Resuming parent PID " << parentPID << " as zombie child exists." << std::endl;
        // No need to change currentCPU as it continues to run
    } else {
        readyQueue.push_back(currentCPU);
        currentCPU = readyQueue.empty() ? NO_PROCESS : readyQueue.front();
        if (currentCPU != NO_PROCESS) readyQueue.pop_front();
        std::cout << "SimWait: Paused parent PID " << parentPID << ", new currentCPU is PID " << currentCPU << std::endl;
        printReadyQueue();
    }
}

void SimOS::TimerInterrupt() {
    if (currentCPU == NO_PROCESS) throw std::logic_error("TimerInterrupt: CPU is idle.");
    readyQueue.push_back(currentCPU);
    currentCPU = readyQueue.front();
    readyQueue.pop_front();
    std::cout << "TimerInterrupt: Timer interrupt, new currentCPU is PID " << currentCPU << std::endl;
    printReadyQueue();
}

void SimOS::DiskReadRequest(int diskNumber, std::string fileName) {
    if (currentCPU == NO_PROCESS) throw std::logic_error("DiskReadRequest: CPU is idle.");
    diskManager.DiskReadRequest(diskNumber, currentCPU, fileName);
    std::cout << "DiskReadRequest: Process " << currentCPU << " requested disk read on disk " << diskNumber << std::endl;
    currentCPU = NO_PROCESS;
    if (!readyQueue.empty()) {
        currentCPU = readyQueue.front();
        readyQueue.pop_front();
    }
    std::cout << "DiskReadRequest: New currentCPU is PID " << currentCPU << std::endl;
    printReadyQueue();
}

void SimOS::DiskJobCompleted(int diskNumber) {
    diskManager.DiskJobCompleted(diskNumber);
    std::cout << "DiskJobCompleted: Disk job completed on disk " << diskNumber << std::endl;
    if (currentCPU == NO_PROCESS && !readyQueue.empty()) {
        currentCPU = readyQueue.front();
        readyQueue.pop_front();
        std::cout << "DiskJobCompleted: New currentCPU is PID " << currentCPU << std::endl;
        printReadyQueue();
    }
}

void SimOS::AccessMemoryAddress(unsigned long long address) {
    if (currentCPU == NO_PROCESS) throw std::logic_error("AccessMemoryAddress: CPU is idle.");
    unsigned long long pageNumber = address / pageSize;
    auto it = std::find_if(memory.begin(), memory.end(),
                           [pageNumber, this](const MemoryItem &item) {
                               return item.pageNumber == pageNumber && item.PID == currentCPU;
                           });
    if (it == memory.end()) {
        if (memory.size() * pageSize >= amountOfRAM) {
            memory.erase(memory.begin());
        }
        memory.push_back({pageNumber, memory.size(), currentCPU});
    }
    std::cout << "AccessMemoryAddress: Accessing memory address " << address << " by PID " << currentCPU << std::endl;
}

int SimOS::GetCPU() {
    return currentCPU;
}

std::deque<int> SimOS::GetReadyQueue() {
    return readyQueue;
}

MemoryUsage SimOS::GetMemory() {
    return memory;
}

FileReadRequest SimOS::GetDisk(int diskNumber) {
    return diskManager.GetDisk(diskNumber);
}

std::deque<FileReadRequest> SimOS::GetDiskQueue(int diskNumber) {
    return diskManager.GetDiskQueue(diskNumber);
}

void SimOS::releaseMemory(int PID) {
    memory.erase(std::remove_if(memory.begin(), memory.end(),
                                [PID](const MemoryItem &item) { return item.PID == PID; }), memory.end());
    std::cout << "releaseMemory: Released memory for PID " << PID << std::endl;
}

void SimOS::terminateProcess(int PID) {
    auto childIt = children.find(PID);
    if (childIt != children.end()) {
        for (int childPID : childIt->second) {
            terminateProcess(childPID);
        }
        children.erase(childIt);
    }

    auto parentIt = parent.find(PID);
    if (parentIt != parent.end()) {
        zombies.insert(PID);
        int parentPID = parentIt->second;
        if (children[parentPID].count(PID)) {
            children[parentPID].erase(PID);
        }
        parent.erase(parentIt);
    }
    std::cout << "terminateProcess: Terminated process with PID " << PID << std::endl;
}

void SimOS::handleOrphans(int PID) {
    if (zombies.count(PID)) {
        zombies.erase(PID);
    }

    for (int childPID : children[PID]) {
        terminateProcess(childPID);
    }
    children.erase(PID);
    std::cout << "handleOrphans: Handled orphans for PID " << PID << std::endl;
}

void SimOS::printReadyQueue() {
    std::cout << "ReadyQueue: ";
    for (int pid : readyQueue) {
        std::cout << pid << " ";
    }
    std::cout << std::endl;
}
