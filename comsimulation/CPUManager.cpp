//
// Created by Prasanga Tiwari on 5/17/24.
//

#include "CPUManager.h"
#include <iostream>


CPUManager::CPUManager() : currentProcess(NO_PROCESS) {
    //std::cout << "CPU Manager initialized with no current process." << std::endl;
}

void CPUManager::addProcess(int pid) {
    if (currentProcess == NO_PROCESS) {
        currentProcess = pid;
        //std::cout << "Process " << pid << " is now running." << std::endl;
    } else {
        readyQueue.push_back(pid);
        //std::cout << "Added process " << pid << " to the ready queue." << std::endl;
    }
}

void CPUManager::removeCurrentProcess() {
    //std::cout << "Removing current process: " << currentProcess << std::endl;
    currentProcess = NO_PROCESS;
    scheduleNextProcess();
}

void CPUManager::scheduleNextProcess() {
    if (!readyQueue.empty()) {
        currentProcess = readyQueue.front();
        readyQueue.pop_front();
        //std::cout << "Scheduled next process. Process " << currentProcess << " is now running." << std::endl;
    } else {
        currentProcess = NO_PROCESS;
        //std::cout << "No process running." << std::endl;
    }
}

void CPUManager::timerInterrupt() {
    if (currentProcess != NO_PROCESS) {
        readyQueue.push_back(currentProcess);
        //std::cout << "Timer interrupt: Moved current process " << currentProcess << " to the ready queue." << std::endl;
    }
    scheduleNextProcess();
    //std::cout << "Timer interrupt: current process " << currentProcess << std::endl;
}

int CPUManager::getCurrentProcess() const {
    return currentProcess;
}

std::deque<int> CPUManager::getReadyQueue() const {
    return readyQueue;
}





