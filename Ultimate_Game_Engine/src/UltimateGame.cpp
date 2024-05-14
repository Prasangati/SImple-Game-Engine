//
// Created by Prasanga Tiwari on 3/3/24.
//
#include "pch.h"
#include "UltimateGame.h"
#include "UltimateWindow.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Image.h"
#include <stb_image.h>
#include "Shader.h"
#include "Renderer.h"
namespace Ultimate{

    void UltimateGame::Initialize() {
    }

    void UltimateGame::OnUpdate() {

    }

    void UltimateGame::ShutDown() {

    }

    void UltimateGame::Run() {
        Renderer::Init();
        UltimateWindow::Init();
        UltimateWindow::GetWindow()->Create(1000, 800);

        /// Shaders //
        Shader sProg("/Users/prasangatiwari/CLionProjects/S24_Prasanga_Tiwari/Ultimate_Game_Engine/Assets/Shaders/DefaultVertexShader.glsl","/Users/prasangatiwari/CLionProjects/S24_Prasanga_Tiwari/Ultimate_Game_Engine/Assets/Shaders/DefaultFragmentShader.glsl");
        ////// Texture /////
        Ultimate::Image pic("/Users/prasangatiwari/CLionProjects/S24_Prasanga_Tiwari/Ultimate_Game_Engine/Assets/Textures/Test.png");

        Initialize();

        while (true) {
            OnUpdate();

            Renderer::ClearScreen();
            Renderer::Draw(pic, 200, 100);

            UltimateWindow::GetWindow()->SwapBuffers();
            UltimateWindow::GetWindow()->PollEvents();
        }
        ShutDown();
        UltimateWindow::Shutdown();
    }



}