//
// Created by Prasanga Tiwari on 5/18/24.
//

#ifndef ANOTHERATTEMPT_DISKMANAGER_H
#define ANOTHERATTEMPT_DISKMANAGER_H

#include <unordered_map>
#include <deque>
#include <string>
#include "utility.h"

class DiskManager {
public:
    DiskManager(int numberOfDisks);

    void DiskReadRequest(int diskNumber, int PID, const std::string& fileName);
    void DiskJobCompleted(int diskNumber);
    FileReadRequest GetDisk(int diskNumber) const;
    std::deque<FileReadRequest> GetDiskQueue(int diskNumber) const;

private:
    int numberOfDisks;
    std::unordered_map<int, std::deque<FileReadRequest>> diskQueues;
    std::unordered_map<int, FileReadRequest> diskJobs;
};

#endif //ANOTHERATTEMPT_DISKMANAGER_H
