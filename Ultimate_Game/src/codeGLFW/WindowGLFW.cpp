//
// Created by Prasanga Tiwari on 4/3/24.
//


#include "pch.h"
#include "WindowGLFW.h"

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

        mWindow = glfwCreateWindow(width, height, "MyGame", NULL, NULL);
        if (!mWindow) {
            std::cerr << "Failed to create GLFW window.\n";
            glfwTerminate();
            exit(EXIT_FAILURE);  // Consider a less drastic handling strategy
        }

        glfwMakeContextCurrent(mWindow);
        std::cout << "Window created and context made current.\n";

        glfwSetWindowUserPointer(mWindow, &mCallbacks);

        glfwSetKeyCallback(mWindow, [](GLFWwindow* window, int keycode, int /*scancode*/, int action, int /*mods*/) {
            if (action == GLFW_PRESS) {
                Callbacks* callbacks = (Callbacks*)glfwGetWindowUserPointer(window);
                KeyPressed e{ keycode };
                callbacks->keyPressedFunc(e);
            } else if (action == GLFW_RELEASE) {
                Callbacks* callbacks = (Callbacks*)glfwGetWindowUserPointer(window);
                KeyReleased e{ keycode };
                callbacks->keyReleasedFunc(e);
            }
        });

        glfwSetWindowCloseCallback(mWindow, [](GLFWwindow* window) {
            Callbacks* callbacks = (Callbacks*)glfwGetWindowUserPointer(window);
            callbacks->windowCloseFunc();
        });
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

    void WindowGLFW::SetKeyPressedCallback(std::function<void(const KeyPressed&)> callbackFunc) {
        mCallbacks.keyPressedFunc = callbackFunc;
    }

    void WindowGLFW::SetKeyReleasedCallback(std::function<void(const KeyReleased&)> callbackFunc) {
        mCallbacks.keyReleasedFunc = callbackFunc;
    }

    void WindowGLFW::SetWindowCloseCallback(std::function<void()> callbackFunc) {
        mCallbacks.windowCloseFunc = callbackFunc;
    }
} // Ultimate