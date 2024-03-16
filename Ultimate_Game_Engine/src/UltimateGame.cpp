//
// Created by Prasanga Tiwari on 3/3/24.
//
#include "pch.h"
#include "UltimateGame.h"

namespace Ultimate{

    void UltimateGame::initialize() {
    }

    void UltimateGame::OnUpdate() {

    }

    void UltimateGame::ShutDown() {

    }

    void UltimateGame::Run() {
        initialize();
        while (true){
            OnUpdate();
        }
        ShutDown();
    }
}