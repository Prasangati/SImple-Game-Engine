//
// Created by Prasanga Tiwari on 3/3/24.
//
#include "pch.h"
#include "UltimateGame.h"
#include "UltimateWindow.h"
namespace Ultimate{

    void UltimateGame::Initialize() {
    }

    void UltimateGame::OnUpdate() {

    }

    void UltimateGame::ShutDown() {

    }

    void UltimateGame::Run() {
        UltimateWindow::Init();
        UltimateWindow::GetWindow()->Create(1000, 800);
        Initialize();
        while (true){
            OnUpdate();
            UltimateWindow::GetWindow()->SwapBuffers();
            UltimateWindow::GetWindow()->SwapBuffers();
        }
        UltimateWindow::Shutdown();
    }
}