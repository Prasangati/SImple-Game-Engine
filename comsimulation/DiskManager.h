//
// Created by Prasanga Tiwari on 5/17/24.
//

#ifndef COMSIMULATION_DISKMANAGER_H
#define COMSIMULATION_DISKMANAGER_H

#include "utility.h"
#include <vector>
#include <deque>
#include <stdexcept>

class DiskManager {
public:
    DiskManager(int numberOfDisks);
    void addRequest(int diskNumber, int pid, const std::string& fileName);
    int completeRequest(int diskNumber);
    FileReadRequest getCurrentRequest(int diskNumber);
    std::deque<FileReadRequest> getRequestQueue(int diskNumber);

private:
    std::vector<std::deque<FileReadRequest>> diskQueues;
};



#endif //COMSIMULATION_DISKMANAGER_H
