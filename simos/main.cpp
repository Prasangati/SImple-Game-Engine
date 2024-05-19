//
// Created by Prasanga Tiwari on 5/18/24.
//
#include "SimOS.h"
#include <iostream>

#include "SimOS.h"
#include <iostream>

int main() {
    SimOS simOS(4, 1024 * 1024 * 64, 4096); // Example initialization

    simOS.NewProcess();
    simOS.NewProcess();
    simOS.SimFork();
    simOS.AccessMemoryAddress(12345);
    simOS.TimerInterrupt();
    simOS.DiskReadRequest(0, "file1.txt");
    simOS.DiskJobCompleted(0);
    simOS.SimExit();
    simOS.SimWait();

    std::cout << "CPU: " << simOS.GetCPU() << std::endl;
    std::cout << "Ready Queue: ";
    for (int pid : simOS.GetReadyQueue()) {
        std::cout << pid << " ";
    }
    std::cout << std::endl;

    return 0;
}

