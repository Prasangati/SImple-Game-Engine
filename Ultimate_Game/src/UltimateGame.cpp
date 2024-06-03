//
// Created by Prasanga Tiwari on 3/3/24.
//
#include "pch.h"
#include "UltimateGame.h"
#include "UltimateWindow.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Image.h"
#include "Shader.h"
#include "Renderer.h"
#include "UltimateKeys.h"
namespace Ultimate{
    UltimateGame::UltimateGame() {
        UltimateWindow::Init();
        UltimateWindow::GetWindow()->Create(1080, 609);

        Renderer::Init();

        SetWindowCloseCallback([this](){DefaultWindowCloseHandler();});

    }

    void UltimateGame::Initialize() {

    }

    void UltimateGame::OnUpdate() {

    }

    void UltimateGame::ShutDown() {

    }

    void UltimateGame::Run() {

        // Texture
        //Ultimate::Image pic("/Users/soleilrosado/CLionProjects/S24_Prasanga_Tiwari/Ultimate_Game/Assets/Textures/scope.jpg");


        Initialize();

        // Initialize mNextFrameTime
        mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

        //int x {0};
        //SetKeyPressedCallback([&x](const KeyPressed& event){
        //    if(event.GetKeyCode() == ULTIMATE_KEY_RIGHT)
        //        x += 50;

        //    if(event.GetKeyCode() == ULTIMATE_KEY_LEFT)
        //        x -= 50;

        //});

        while (mShouldContinue) {
            Renderer::ClearScreen();
            OnUpdate();

            //Renderer::Draw(pic, x, 100);

            // Sleep until the next frame time
            std::this_thread::sleep_until(mNextFrameTime);
            // Update mNextFrameTime
            mNextFrameTime += mFrameDuration;

            UltimateWindow::GetWindow()->SwapBuffers();
            UltimateWindow::GetWindow()->PollEvents();
        }

        ShutDown();
        UltimateWindow::Shutdown();
    }

    void UltimateGame::SetWindowCloseCallback(const std::function<void()>& callbackFunc) {
        UltimateWindow::GetWindow()->SetWindowCloseCallback(callbackFunc);
    }

    void UltimateGame::SetKeyPressedCallback(const std::function<void(const KeyPressed&)>& callbackFunc) {
        UltimateWindow::GetWindow()->SetKeyPressedCallback(callbackFunc);
    }

    void UltimateGame::SetKeyReleasedCallback(const std::function<void(const KeyReleased&)>& callbackFunc) {
        UltimateWindow::GetWindow()->SetKeyReleasedCallback(callbackFunc);
    }


    void UltimateGame::DefaultWindowCloseHandler() {
        mShouldContinue = false;
    }


}