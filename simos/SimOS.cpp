#include "SimOS.h"
#include <iostream>


// Constructor
SimOS::SimOS(int numberOfDisks, unsigned long long amountOfRAM, unsigned int pageSize)
        : numberOfDisks(numberOfDisks), amountOfRAM(amountOfRAM), pageSize(pageSize), currentPID(0), currentCPUProcess(NO_PROCESS) {
    disks.resize(numberOfDisks);
    diskQueues.resize(numberOfDisks);
}

void SimOS::reassignCPU() {
    if (currentCPUProcess == NO_PROCESS && !readyQueue.empty()) {
        currentCPUProcess = readyQueue.front();
        readyQueue.pop_front();
        std::cout << "CPU assigned to next process: PID = " << currentCPUProcess << std::endl;
    } else if (currentCPUProcess == NO_PROCESS) {
        std::cout << "CPU is now idle." << std::endl;
    }
}

// Method to create a new process
void SimOS::NewProcess() {
    currentPID++;
    readyQueue.push_back(currentPID);
    std::cout << "New Process Created: PID = " << currentPID << std::endl;
    if (currentCPUProcess == NO_PROCESS) {
        reassignCPU();
    }
}

// Method to fork the currently running process
void SimOS::SimFork() {
    if (currentCPUProcess == NO_PROCESS) throw std::logic_error("CPU is idle.");
    currentPID++;
    readyQueue.push_back(currentPID);
    processChildren[currentCPUProcess].push_back(currentPID);
    processParent[currentPID] = currentCPUProcess;
    std::cout << "Process Forked: Parent PID = " << currentCPUProcess << ", Child PID = " << currentPID << std::endl;
}

// Method to terminate the currently running process
void SimOS::SimExit() {
    if (currentCPUProcess == NO_PROCESS) throw std::logic_error("CPU is idle.");
    int pid = currentCPUProcess;
    terminateProcess(pid);
    std::cout << "Process Terminated: PID = " << pid << std::endl;

    currentCPUProcess = NO_PROCESS;
    reassignCPU();
}

void SimOS::terminateProcess(int pid) {
    for (auto child : processChildren[pid]) {
        terminateProcess(child);
    }
    processChildren.erase(pid);
    processParent.erase(pid);
    processWaiting.erase(pid);
    zombieProcesses.erase(pid);

    for (auto it = memory.begin(); it != memory.end();) {
        if (it->PID == pid) {
            lruPages.erase(std::remove(lruPages.begin(), lruPages.end(), it->frameNumber), lruPages.end());
            it = memory.erase(it);
        } else {
            ++it;
        }
    }
}

// Method for a process to wait for its child to terminate
void SimOS::SimWait() {
    if (currentCPUProcess == NO_PROCESS) throw std::logic_error("CPU is idle.");
    int pid = currentCPUProcess;
    bool zombieExists = false;
    for (auto child : processChildren[pid]) {
        if (zombieProcesses[child]) {
            zombieExists = true;
            terminateProcess(child);
            std::cout << "Zombie process handled: PID = " << child << std::endl;
            break;
        }
    }
    if (!zombieExists) {
        processWaiting[pid] = true;
        currentCPUProcess = NO_PROCESS;
        reassignCPU();
    }
}

// Method to handle timer interrupts
void SimOS::TimerInterrupt() {
    if (currentCPUProcess == NO_PROCESS) throw std::logic_error("CPU is idle.");
    readyQueue.push_back(currentCPUProcess);
    currentCPUProcess = NO_PROCESS;
    reassignCPU();
    std::cout << "Timer interrupt: CPU switched to PID = " << currentCPUProcess << std::endl;
}

// Method to handle disk read requests
void SimOS::DiskReadRequest(int diskNumber, const std::string& fileName) {
    if (currentCPUProcess == NO_PROCESS) throw std::logic_error("CPU is idle.");
    if (diskNumber >= numberOfDisks) throw std::out_of_range("Disk number out of range.");
    FileReadRequest request{currentCPUProcess, fileName};
    diskQueues[diskNumber].push_back(request);
    std::cout << "Disk read request: PID = " << currentCPUProcess << ", Disk = " << diskNumber << ", File = " << fileName << std::endl;
    if (disks[diskNumber].PID == NO_PROCESS) {
        disks[diskNumber] = diskQueues[diskNumber].front();
        diskQueues[diskNumber].pop_front();
        std::cout << "Disk assigned to request: Disk = " << diskNumber << std::endl;
    }
    currentCPUProcess = NO_PROCESS;
    reassignCPU();
}

// Method to handle disk job completions
void SimOS::DiskJobCompleted(int diskNumber) {
    if (diskNumber >= numberOfDisks) throw std::out_of_range("Disk number out of range.");

    if (disks[diskNumber].PID != NO_PROCESS) {
        readyQueue.push_back(disks[diskNumber].PID);
        std::cout << "Disk job completed: PID = " << disks[diskNumber].PID << ", Disk = " << diskNumber << std::endl;
        disks[diskNumber] = FileReadRequest();
    }

    if (!diskQueues[diskNumber].empty()) {
        disks[diskNumber] = diskQueues[diskNumber].front();
        diskQueues[diskNumber].pop_front();
        std::cout << "Disk assigned to next request: Disk = " << diskNumber << std::endl;
    }

    reassignCPU();
}

// Method to access a memory address
void SimOS::AccessMemoryAddress(unsigned long long address) {
    if (currentCPUProcess == NO_PROCESS) throw std::logic_error("CPU is idle.");
    unsigned long long pageNumber = address / pageSize;
    unsigned long long frameNumber = pageNumber % (amountOfRAM / pageSize);
    for (auto &item : memory) {
        if (item.pageNumber == pageNumber && item.PID == currentCPUProcess) {
            lruPages.erase(std::remove(lruPages.begin(), lruPages.end(), item.frameNumber), lruPages.end());
            lruPages.push_back(item.frameNumber);
            std::cout << "Memory access: Page hit, PID = " << currentCPUProcess << ", Page = " << pageNumber << std::endl;
            return;
        }
    }
    if (memory.size() * pageSize >= amountOfRAM) {
        unsigned long long frameToRemove = lruPages.front();
        lruPages.pop_front();
        for (auto it = memory.begin(); it != memory.end(); ++it) {
            if (it->frameNumber == frameToRemove) {
                memory.erase(it);
                break;
            }
        }
    }
    MemoryItem newItem{pageNumber, frameNumber, currentCPUProcess};
    memory.push_back(newItem);
    lruPages.push_back(frameNumber);
    std::cout << "Memory access: Page fault, PID = " << currentCPUProcess << ", Page = " << pageNumber << std::endl;
}

// Method to get the PID of the currently running process
int SimOS::GetCPU() const {
    return currentCPUProcess;
}

// Method to get the ready queue
std::deque<int> SimOS::GetReadyQueue() const {
    return readyQueue;
}

// Method to get memory usage
MemoryUsage SimOS::GetMemory() const {
    return memory;
}

// Method to get the disk status
FileReadRequest SimOS::GetDisk(int diskNumber) const {
    if (diskNumber >= numberOfDisks) throw std::out_of_range("Disk number out of range.");
    return disks[diskNumber];
}

// Method to get the disk queue
std::deque<FileReadRequest> SimOS::GetDiskQueue(int diskNumber) const {
    if (diskNumber >= numberOfDisks) throw std::out_of_range("Disk number out of range.");
    return diskQueues[diskNumber];
}
