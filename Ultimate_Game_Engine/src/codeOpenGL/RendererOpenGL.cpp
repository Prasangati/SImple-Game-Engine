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
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        ULTIMATE_ERROR("Failed to initialize GLAD");
        return;
    }

    // Get the base path of the current file
    std::string basePath = std::filesystem::path(__FILE__).parent_path().string();
    std::string vertexShaderPath = basePath + "/Assets/Shaders/DefaultVertexShader.glsl";
    std::string fragmentShaderPath = basePath + "/Assets/Shaders/DefaultFragmentShader.glsl";

    mShaderPtr = std::unique_ptr<Shader>{new Shader{vertexShaderPath, fragmentShaderPath}};

    // Blending
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}




Ultimate::RendererOpenGL::~RendererOpenGL() {

}

void Ultimate::RendererOpenGL::Draw(Image &pic, int x, int y) {
    unsigned int VBO, VAO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

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

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    mShaderPtr->Bind();
    mShaderPtr->SetUniform2Ints("ScreenSize", UltimateWindow::GetWindow()->GetWidth(), UltimateWindow::GetWindow()->GetHeight());

    glActiveTexture(GL_TEXTURE0);
    pic.Bind();

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    glBindVertexArray(0);

    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    glDeleteVertexArrays(1, &VAO);
}

void Ultimate::RendererOpenGL::Draw(Ultimate::Image &pic, Ultimate::Shader &shader, int x, int y) {
    unsigned int VBO, VAO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

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

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    shader.Bind();
    shader.SetUniform2Ints("ScreenSize", UltimateWindow::GetWindow()->GetWidth(), UltimateWindow::GetWindow()->GetHeight());

    glActiveTexture(GL_TEXTURE0);
    pic.Bind();

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    glBindVertexArray(0);

    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    glDeleteVertexArrays(1, &VAO);
}

void Ultimate::RendererOpenGL::ClearScreen() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Sets the background color to white
    glClear(GL_COLOR_BUFFER_BIT);
}

