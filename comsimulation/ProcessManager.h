//
// Created by Prasanga Tiwari on 5/10/24.
//

#ifndef COMSIMULATION_PROCESSMANAGER_H
#define COMSIMULATION_PROCESSMANAGER_H

#include "utility.h"
#include <unordered_map>
#include <deque>
#include <vector>

struct Process {
    int PID;
    int parentPID;
    bool isZombie;
    bool isWaiting;
    std::vector<int> childPIDs;

    Process() : PID(NO_PROCESS), parentPID(NO_PROCESS), isZombie(false), isWaiting(false) {}

    Process(int pid, int parent) : PID(pid), parentPID(parent), isZombie(false), isWaiting(false) {}
};

class ProcessManager {
public:
    ProcessManager();
    int createProcess();
    int forkProcess(int parentPID);
    void terminateProcess(int pid);
    bool waitProcess(int pid);

private:
    int nextPID;
    std::unordered_map<int, Process> processes;
};



#endif //COMSIMULATION_PROCESSMANAGER_H
