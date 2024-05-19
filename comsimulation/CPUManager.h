//
// Created by Prasanga Tiwari on 5/02/24.
//

#ifndef COMSIMULATION_CPUMANAGER_H
#define COMSIMULATION_CPUMANAGER_H
#include "utility.h"
#include <deque>

class CPUManager {
public:
    CPUManager();
    void addProcess(int pid);
    void removeCurrentProcess();
    void timerInterrupt();
    int getCurrentProcess() const;
    std::deque<int> getReadyQueue() const;

private:
    void scheduleNextProcess();
    int currentProcess;
    std::deque<int> readyQueue;
};




#endif //COMSIMULATION_CPUMANAGER_H
