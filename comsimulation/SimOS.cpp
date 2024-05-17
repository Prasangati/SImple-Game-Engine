//
// Created by Prasanga Tiwari on 5/16/24.
//
#include "SimOS.h"
#include <iostream>

SimOS::SimOS(int numberOfDisks, unsigned long long amountOfRAM, unsigned int pageSize)
        : cpu(), memoryManager(amountOfRAM, pageSize), diskManager(numberOfDisks), processManager() {
    std::cout << "SimOS initialized with " << numberOfDisks << " disks, " << amountOfRAM << " bytes of RAM, page size " << pageSize << " bytes." << std::endl;
}

void SimOS::NewProcess() {
    int pid = processManager.createProcess();
    cpu.addProcess(pid);
    std::cout << "New process created with PID " << pid << std::endl;
}

void SimOS::SimFork() {
    int parentPid = cpu.getCurrentProcess();
    if (parentPid == NO_PROCESS) throw std::logic_error("CPU is idle");

    int childPid = processManager.forkProcess(parentPid);
    cpu.addProcess(childPid);
    std::cout << "Forked process " << childPid << " from parent " << parentPid << std::endl;
}

void SimOS::SimExit() {
    int pid = cpu.getCurrentProcess();
    if (pid == NO_PROCESS) throw std::logic_error("CPU is idle");

    processManager.terminateProcess(pid);
    memoryManager.releaseMemory(pid);
    cpu.removeCurrentProcess();
    std::cout << "Process " << pid << " exited." << std::endl;
    cpu.timerInterrupt();  // Ensure the next process is scheduled
}

void SimOS::SimWait() {
    int pid = cpu.getCurrentProcess();
    if (pid == NO_PROCESS) throw std::logic_error("CPU is idle");

    if (processManager.waitProcess(pid)) {
        std::cout << "Process " << pid << " found and erased a zombie child process." << std::endl;
    } else {
        cpu.removeCurrentProcess();
        std::cout << "Process " << pid << " is waiting." << std::endl;
    }
    cpu.timerInterrupt();  // Ensure the next process is scheduled
}

void SimOS::TimerInterrupt() {
    cpu.timerInterrupt();
    std::cout << "Timer interrupt occurred." << std::endl;
}

void SimOS::DiskReadRequest(int diskNumber, std::string fileName) {
    int pid = cpu.getCurrentProcess();
    if (pid == NO_PROCESS) throw std::logic_error("CPU is idle");

    diskManager.addRequest(diskNumber, pid, fileName);
    cpu.removeCurrentProcess();
    std::cout << "Disk read request by PID " << pid << " for file " << fileName << " on disk " << diskNumber << std::endl;
    cpu.timerInterrupt();  // Ensure the next process is scheduled
}

void SimOS::DiskJobCompleted(int diskNumber) {
    int pid = diskManager.completeRequest(diskNumber);
    if (pid != NO_PROCESS) {
        cpu.addProcess(pid);
        std::cout << "Disk job completed for PID " << pid << " on disk " << diskNumber << std::endl;
    }
}

void SimOS::AccessMemoryAddress(unsigned long long address) {
    int pid = cpu.getCurrentProcess();
    if (pid == NO_PROCESS) throw std::logic_error("CPU is idle");

    memoryManager.accessMemory(pid, address);
    std::cout << "Memory access by PID " << pid << " to address " << address << std::endl;
    cpu.timerInterrupt();  // Ensure the next process is scheduled
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
    return diskManager.getRequestQueue(diskNumber);
}
