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

    // Set the viewport
    glViewport(0, 0, UltimateWindow::GetWindow()->GetWidth(), UltimateWindow::GetWindow()->GetHeight());
}




Ultimate::RendererOpenGL::~RendererOpenGL() {

}

void Ultimate::RendererOpenGL::Draw(Ultimate::Image &pic, int x, int y) {
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

    pic.Bind();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    // Unbind
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    // Clean up
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);

    // Debugging: Check for OpenGL errors
    GLenum error = glGetError();
    if (error != GL_NO_ERROR) {
        std::cerr << "OpenGL Error: " << error << std::endl;
    }
}

void Ultimate::RendererOpenGL::Draw(Ultimate::Image &pic, Ultimate::Shader &shader, int x, int y) {
    float vertices[] = {
            // positions          // texture coords
            static_cast<float>(x), static_cast<float>(y + pic.GetHeight()), 0.0f, 1.0f, // bottom left
            static_cast<float>(x + pic.GetWidth()), static_cast<float>(y + pic.GetHeight()), 1.0f, 1.0f, // bottom right
            static_cast<float>(x + pic.GetWidth()), static_cast<float>(y), 1.0f, 0.0f, // top right
            static_cast<float>(x), static_cast<float>(y), 0.0f, 0.0f  // top left
    };

    unsigned int indices[] = {
            0, 1, 2,
            2, 3, 0
    };

    unsigned int VBO, VAO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // Position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // Texture coord attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    shader.Bind();
    shader.SetUniform2Ints("ScreenSize", UltimateWindow::GetWindow()->GetWidth(), UltimateWindow::GetWindow()->GetHeight());

    glActiveTexture(GL_TEXTURE0);
    pic.Bind();

    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    glBindVertexArray(0);

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}

void Ultimate::RendererOpenGL::ClearScreen() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Sets the background color to white
    glClear(GL_COLOR_BUFFER_BIT);
}

