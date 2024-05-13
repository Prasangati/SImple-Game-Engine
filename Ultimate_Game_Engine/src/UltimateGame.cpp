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
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            ULTIMATE_ERROR("Failed to initialize GLAD");
            return;
        }

        /// Blending ///
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        /// Vertex Data ///
        unsigned int VBO, VAO;
        glGenVertexArrays(1, &VAO);
        glBindVertexArray(VAO);

        float vertices[] = {
                -0.5f, -0.5f, 0.0, 0.0,
                0.5f, -0.5f, 1.0, 0.0,
                -0.5f, 0.5f, 0.0, 1.0,
                0.5f, 0.5f, 1.0, 1.0
        };

        unsigned int indices[] = {
                0, 1, 2,
                1, 2, 3
        };

        glGenBuffers(1, &VBO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
        glEnableVertexAttribArray(1);

        unsigned int EBO;
        glGenBuffers(1, &EBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

        /// Shaders //
        Shader sProg("/Users/prasangatiwari/CLionProjects/S24_Prasanga_Tiwari/Ultimate_Game_Engine/Assets/Shaders/DefaultVertexShader.glsl","/Users/prasangatiwari/CLionProjects/S24_Prasanga_Tiwari/Ultimate_Game_Engine/Assets/Shaders/DefaultFragmentShader.glsl");
        ////// Texture /////
        Ultimate::Image pic("/Users/prasangatiwari/CLionProjects/S24_Prasanga_Tiwari/Ultimate_Game_Engine/Assets/Textures/Test.png");

        Initialize();

        while (true) {
            OnUpdate();

            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            sProg.Bind();
            glBindVertexArray(VAO);
            pic.Bind();
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

            UltimateWindow::GetWindow()->SwapBuffers();
            UltimateWindow::GetWindow()->PollEvents();
        }
        ShutDown();
        UltimateWindow::Shutdown();
    }



}