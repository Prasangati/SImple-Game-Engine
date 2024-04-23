//
// Created by Prasanga Tiwari on 4/3/24.
//

#include "WindowGLFW.h"
#include "../pch.h"

namespace Ultimate {
    WindowGLFW::WindowGLFW() {
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    }

    void WindowGLFW::Create(int width, int height) {
        mWindow = glfwCreateWindow(width,height,"MyGame",NULL,NULL);
        assert(mWindow != NULL);
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

    WindowGLFW::~WindowGLFW() {
        glfwTerminate();
    }
} // Ultimate