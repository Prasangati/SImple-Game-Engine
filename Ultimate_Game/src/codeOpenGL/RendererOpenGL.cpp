//
// Created by Prasanga Tiwari on 5/13/24.
//
#include "pch.h"
#include "RendererOpenGL.h"
#define GLFW_INCLUDE_NONE
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "UltimateWindow.h"
Ultimate::RendererOpenGL::RendererOpenGL() {
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        ULTIMATE_ERROR("Failed to initialize GLAD");
        return;
    }

    mShaderPtr = std::unique_ptr<Shader>{new Shader{"../Assets/Shaders/DefaultVertexShader.glsl", "../Assets/Shaders/DefaultFragmentShader.glsl"}};
    /// Blending ///
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

}

Ultimate::RendererOpenGL::~RendererOpenGL() {

}

void Ultimate::RendererOpenGL::Draw(Ultimate::Image &pic, int x, int y) {
    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    float vertices[] = {
            static_cast<float>(x), static_cast<float>(y), 0.0f, 0.0f,
            static_cast<float>(x + pic.GetWidth()), static_cast<float>(y), 1.0f, 0.0f,
            static_cast<float>(x), static_cast<float>(y + pic.GetHeight()), 0.0f, 1.0f,
            static_cast<float>(x + pic.GetWidth()), static_cast<float>(y + pic.GetHeight()), 1.0f, 1.0f
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

    mShaderPtr->Bind();
    mShaderPtr->SetUniform2Ints("ScreenSize",UltimateWindow::GetWindow()->GetWidth(),UltimateWindow::GetWindow()->GetHeight());
    glBindVertexArray(VAO);
    pic.Bind();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void Ultimate::RendererOpenGL::Draw(Ultimate::Image &pic, Ultimate::Shader &shader, int x, int y) {
    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    float vertices[] = {
            static_cast<float>(x), static_cast<float>(y), 0.0f, 0.0f,
            static_cast<float>(x + pic.GetWidth()), static_cast<float>(y), 1.0f, 0.0f,
            static_cast<float>(x), static_cast<float>(y + pic.GetHeight()), 0.0f, 1.0f,
            static_cast<float>(x + pic.GetWidth()), static_cast<float>(y + pic.GetHeight()), 1.0f, 1.0f
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

    shader.Bind();
    glBindVertexArray(VAO);
    pic.Bind();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

}

void Ultimate::RendererOpenGL::ClearScreen() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}
