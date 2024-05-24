//
// Created by Prasanga Tiwari on 5/16/24.
//
#include "SimOS.h"


SimOS::SimOS(int numberOfDisks, unsigned long long amountOfRAM, unsigned int pageSize)
        : cpu(), memoryManager(amountOfRAM, pageSize), diskManager(numberOfDisks), processManager() {}

void SimOS::NewProcess() {
    int pid = processManager.createProcess();
    cpu.addProcess(pid);
}

void SimOS::SimFork() {
    int parentPid = cpu.getCurrentProcess();
    if (parentPid == NO_PROCESS) throw std::logic_error("CPU is idle");

    int childPid = processManager.forkProcess(parentPid);
    cpu.addProcess(childPid);
}

void SimOS::SimExit() {
    int pid = cpu.getCurrentProcess();
    if (pid == NO_PROCESS) throw std::logic_error("CPU is idle");

    processManager.terminateProcess(pid);
    memoryManager.releaseMemory(pid);
    cpu.removeCurrentProcess();
    cpu.timerInterrupt();  // Ensure the next process is scheduled
}

void SimOS::SimWait() {
    int pid = cpu.getCurrentProcess();
    if (pid == NO_PROCESS) throw std::logic_error("CPU is idle");

    if (processManager.waitProcess(pid)) {
        // Process found and erased a zombie child process
    } else {
        cpu.removeCurrentProcess();
    }
    cpu.timerInterrupt();  // Ensure the next process is scheduled
}

void SimOS::TimerInterrupt() {
    cpu.timerInterrupt();
}

void SimOS::DiskReadRequest(int diskNumber, std::string fileName) {
    int pid = cpu.getCurrentProcess();
    if (pid == NO_PROCESS) throw std::logic_error("CPU is idle");

    diskManager.addRequest(diskNumber, pid, fileName);
    cpu.removeCurrentProcess();
    cpu.timerInterrupt();  // Ensure the next process is scheduled
}

void SimOS::DiskJobCompleted(int diskNumber) {
    int pid = diskManager.completeRequest(diskNumber);
    if (pid != NO_PROCESS) {
        cpu.addProcess(pid);
    }
}

void SimOS::AccessMemoryAddress(unsigned long long address) {
    int pid = cpu.getCurrentProcess();
    if (pid == NO_PROCESS) throw std::logic_error("CPU is idle");

    memoryManager.accessMemory(pid, address);
}

int SimOS::GetCPU() {
    return cpu.getCurrentProcess();
}

std::deque<int> SimOS::GetReadyQueue() {
    return cpu.getReadyQueue();
}

MemoryUsage SimOS::GetMemory() {
    return memoryManager.getMemoryUsage();
}

FileReadRequest SimOS::GetDisk(int diskNumber) {
    return diskManager.getCurrentRequest(diskNumber);
}

std::deque<FileReadRequest> SimOS::GetDiskQueue(int diskNumber) {
    // Complete the disk job before returning the queue
    DiskJobCompleted(diskNumber);
    return diskManager.getRequestQueue(diskNumber);
}


