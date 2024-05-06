//
// Created by Prasanga Tiwari on 4/3/24.
//

#include "WindowGLFW.h"
#include "../pch.h"

namespace Ultimate {
    WindowGLFW::WindowGLFW() {
        if (!glfwInit()) {
            std::cerr << "GLFW initialization failed on constructor.\n";
            exit(EXIT_FAILURE);  // Consider a less drastic handling strategy
        }
        glfwSetErrorCallback([](int error, const char* description) {
            std::cerr << "GLFW Error (" << error << "): " << description << '\n';
        });
    }

    void WindowGLFW::Create(int width, int height) {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

        mWindow = glfwCreateWindow(width, height, "MyGame", NULL, NULL);
        if (!mWindow) {
            std::cerr << "Failed to create GLFW window.\n";
            glfwTerminate();
            exit(EXIT_FAILURE);  // Consider a less drastic handling strategy
        }

        glfwMakeContextCurrent(mWindow);
        std::cout << "Window created and context made current.\n";
    }

    void WindowGLFW::SwapBuffers() {
        glfwSwapBuffers(mWindow);
    }

    void WindowGLFW::PollEvents() {
        glfwPollEvents();
    }

    bool WindowGLFW::IsValid() const {
        return mWindow != nullptr;
    }
    int WindowGLFW::GetWidth() const {
        int width, height;
        glfwGetWindowSize(mWindow,&width,&height);
        return width;
    }
    int WindowGLFW::GetHeight() const {
        int width, height;
        glfwGetWindowSize(mWindow, &width, &height);
        return height;  // Return the height
    }

    void WindowGLFW::glfeveninfo() const {
        glfwPollEvents();
    }

    WindowGLFW::~WindowGLFW() {
        if (mWindow) {
            glfwDestroyWindow(mWindow);
        }
        glfwTerminate();
    }
} // Ultimate