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

        const char* vertexShaderSource = R"(
        #version 330 core
        layout (location = 0) in vec2 aPos;
        layout (location = 1) in vec2 aTexCoord;

        out vec2 TexCoord;

        void main()
        {
            gl_Position = vec4(aPos.x, aPos.y, 0.0, 1.0);
            TexCoord = aTexCoord;
        }
    )";

        const char* fragmentShaderSource = R"(
        #version 330 core
        out vec4 FragColor;

        in vec2 TexCoord;

        uniform sampler2D myTex;

        void main()
        {
            FragColor = texture(myTex, TexCoord);
        }
    )";

        unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
        glCompileShader(vertexShader);
        int success;
        char infoLog[512];
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
            ULTIMATE_ERROR("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog);
        }

        unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
        glCompileShader(fragmentShader);
        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
            ULTIMATE_ERROR("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog);
        }

        unsigned int shaderProgram = glCreateProgram();
        glAttachShader(shaderProgram, vertexShader);
        glAttachShader(shaderProgram, fragmentShader);
        glLinkProgram(shaderProgram);
        // Check for linking errors
        glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
            ULTIMATE_ERROR("ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog);
        }
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);

        ////// Texture /////
        Ultimate::Image pic("/Users/prasangatiwari/CLionProjects/S24_Prasanga_Tiwari/Ultimate_Game_Engine/Assets/Textures/Test.png");

        Initialize();

        while (true) {
            OnUpdate();

            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            glUseProgram(shaderProgram);
            glUniform1i(glGetUniformLocation(shaderProgram, "myTex"), 0);
            glActiveTexture(GL_TEXTURE0);
            pic.Bind();
            glBindVertexArray(VAO);
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

            UltimateWindow::GetWindow()->SwapBuffers();
            UltimateWindow::GetWindow()->PollEvents();
        }
        ShutDown();
        UltimateWindow::Shutdown();
    }



}