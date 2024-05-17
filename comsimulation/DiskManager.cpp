//
// Created by Prasanga Tiwari on 5/17/24.
//

#include "DiskManager.h"
#include <iostream>

DiskManager::DiskManager(int numberOfDisks) : diskQueues(numberOfDisks) {
    std::cout << "DiskManager initialized with " << numberOfDisks << " disks." << std::endl;
}

void DiskManager::addRequest(int diskNumber, int pid, const std::string& fileName) {
    if (diskNumber < 0 || diskNumber >= diskQueues.size()) {
        throw std::out_of_range("Invalid disk number");
    }

    FileReadRequest request{pid, fileName};
    diskQueues[diskNumber].push_back(request);
    std::cout << "Added request to disk " << diskNumber << ": PID = " << pid << ", file = " << fileName << std::endl;
    std::cout << "Current disk " << diskNumber << " queue size: " << diskQueues[diskNumber].size() << std::endl;
}

int DiskManager::completeRequest(int diskNumber) {
    if (diskNumber < 0 || diskNumber >= diskQueues.size()) {
        throw std::out_of_range("Invalid disk number");
    }

    if (diskQueues[diskNumber].empty()) {
        return NO_PROCESS;
    }

    FileReadRequest completedRequest = diskQueues[diskNumber].front();
    diskQueues[diskNumber].pop_front();
    std::cout << "Completed request on disk " << diskNumber << ": PID = " << completedRequest.PID << std::endl;
    std::cout << "Current disk " << diskNumber << " queue size: " << diskQueues[diskNumber].size() << std::endl;
    return completedRequest.PID;
}

FileReadRequest DiskManager::getCurrentRequest(int diskNumber) {
    if (diskNumber < 0 || diskNumber >= diskQueues.size()) {
        throw std::out_of_range("Invalid disk number");
    }

    if (diskQueues[diskNumber].empty()) {
        return FileReadRequest{};
    }

    return diskQueues[diskNumber].front();
}

std::deque<FileReadRequest> DiskManager::getRequestQueue(int diskNumber) {
    if (diskNumber < 0 || diskNumber >= diskQueues.size()) {
        throw std::out_of_range("Invalid disk number");
    }

    std::cout << "Retrieving request queue for disk " << diskNumber << ": size = " << diskQueues[diskNumber].size() << std::endl;
    return diskQueues[diskNumber];
}

