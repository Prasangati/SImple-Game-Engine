// Prasanga Tiwari
#include "ProcessManager.h"


ProcessManager::ProcessManager() : nextPID(1) {
    //std::cout << "ProcessManager initialized." << std::endl;
}

int ProcessManager::createProcess() {
    Process newProcess(nextPID, NO_PROCESS);
    processes[nextPID] = newProcess;
    //std::cout << "Created process with PID " << nextPID << std::endl;
    return nextPID++;
}

int ProcessManager::forkProcess(int parentPID) {
    if (processes.find(parentPID) == processes.end()) {
        throw std::logic_error("Parent process does not exist.");
    }
    Process newProcess(nextPID, parentPID);
    processes[nextPID] = newProcess;
    processes[parentPID].childPIDs.push_back(nextPID);
    //std::cout << "Forked process with PID " << nextPID << " from parent " << parentPID << std::endl;
    return nextPID++;
}

void ProcessManager::terminateProcess(int pid) {
    auto processIt = processes.find(pid);
    if (processIt == processes.end()) {
        //std::cerr << "Error: Attempted to terminate a non-existent process " << pid << std::endl;
        throw std::logic_error("Process does not exist.");
    }

    // Cascade termination for child processes
    for (int childPID : processIt->second.childPIDs) {
        if (processes.find(childPID) != processes.end()) {
            terminateProcess(childPID);
        }
    }

    // If the process has a parent waiting for it, remove the process
    if (processIt->second.parentPID != NO_PROCESS && processes.find(processIt->second.parentPID) != processes.end() && processes[processIt->second.parentPID].isWaiting) {
        processes[processIt->second.parentPID].isWaiting = false;
        processes.erase(pid);
        //std::cout << "Parent " << processIt->second.parentPID << " was waiting. Erased process " << pid << std::endl;
    } else if (processIt->second.isZombie) {
        // If the process is already a zombie, just erase it
        processes.erase(pid);
        //std::cout << "Erased already zombie process " << pid << std::endl;
    } else {
        // Mark the process as a zombie if its parent is not waiting
        processIt->second.isZombie = true;
        //std::cout << "Marked process " << pid << " as zombie." << std::endl;
    }
}

bool ProcessManager::waitProcess(int pid) {
    auto processIt = processes.find(pid);
    if (processIt == processes.end()) {
        //std::cerr << "Error: Attempted to wait on a non-existent process " << pid << std::endl;
        throw std::logic_error("Process does not exist.");
    }

    bool foundZombie = false;
    for (int childPID : processIt->second.childPIDs) {
        auto childIt = processes.find(childPID);
        if (childIt != processes.end() && childIt->second.isZombie) {
            processes.erase(childPID);
            foundZombie = true;
            //std::cout << "Erased zombie child process " << childPID << std::endl;
            break;
        }
    }

    if (foundZombie) {
        return true;
    } else {
        processIt->second.isWaiting = true;
        //std::cout << "Process " << pid << " is waiting for its child processes." << std::endl;
        return false;
    }
}





