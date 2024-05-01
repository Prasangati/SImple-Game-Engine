//
// Created by Prasanga Tiwari on 3/3/24.
//
#include "pch.h"
#include "UltimateGame.h"

#include <GL/gl.h>

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
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            ULTIMATE_ERROR("Failed to initialized GLAD");
            return;
        }

        ///Blending///
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        /// Vertex Data ///

        unsigned int VBO, VAO;
        glGenVertexArrays(1,&VAO);

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

        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2* sizeof(float)));
        glEnableVertexAttribArray(1);

        unsigned int EBO;
        glGenBuffers(1, &EBO);








    }

}