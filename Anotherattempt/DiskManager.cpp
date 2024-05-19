//
// Created by Prasanga Tiwari on 5/18/24.
//

#include "DiskManager.h"
#include <stdexcept>
#include <iostream>

DiskManager::DiskManager(int numberOfDisks) : numberOfDisks(numberOfDisks) {
    for (int i = 0; i < numberOfDisks; ++i) {
        diskQueues[i] = std::deque<FileReadRequest>();
        diskJobs[i] = {NO_PROCESS, ""};
    }
}

void DiskManager::DiskReadRequest(int diskNumber, int PID, const std::string& fileName) {
    if (diskNumber >= numberOfDisks || diskNumber < 0) throw std::out_of_range("Invalid disk number.");
    if (diskJobs[diskNumber].PID == NO_PROCESS) {
        diskJobs[diskNumber] = {PID, fileName};
        std::cout << "DiskReadRequest: Process " << PID << " requested disk read on disk " << diskNumber << " (assigned directly)" << std::endl;
    } else {
        diskQueues[diskNumber].push_back({PID, fileName});
        std::cout << "DiskReadRequest: Process " << PID << " requested disk read on disk " << diskNumber << " (queued)" << std::endl;
    }
}

void DiskManager::DiskJobCompleted(int diskNumber) {
    if (diskNumber >= numberOfDisks || diskNumber < 0) throw std::out_of_range("Invalid disk number.");
    if (!diskQueues[diskNumber].empty()) {
        auto completedJob = diskQueues[diskNumber].front();
        diskQueues[diskNumber].pop_front();
        diskJobs[diskNumber] = completedJob;
        std::cout << "DiskJobCompleted: Completed job for process " << completedJob.PID << " on disk " << diskNumber << std::endl;
    } else {
        diskJobs[diskNumber] = {NO_PROCESS, ""};
    }
}

FileReadRequest DiskManager::GetDisk(int diskNumber) const {
    if (diskNumber >= numberOfDisks || diskNumber < 0) throw std::out_of_range("Invalid disk number.");
    return diskJobs.at(diskNumber);
}

std::deque<FileReadRequest> DiskManager::GetDiskQueue(int diskNumber) const {
    if (diskNumber >= numberOfDisks || diskNumber < 0) throw std::out_of_range("Invalid disk number.");
    return diskQueues.at(diskNumber);
}
