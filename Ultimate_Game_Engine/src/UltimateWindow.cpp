//
// Created by Prasanga Tiwari on 4/3/24.
//
#include "pch.h"
#include "codeGLFW/WindowGLFW.h"
#include "UltimateWindow.h"

namespace Ultimate {
    UltimateWindow::UltimateWindow() {
        #ifdef ULTIMATE_GLFW_WINDOW
        mWindow = std::unique_ptr<WindowImpl>{new WindowGLFW};  // Ensure correct member variable is used
        #else
        #error "GLFW window implementation is missing"
        #endif
    }

    void UltimateWindow::Create(int width, int height) {
        mWindow->Create(width, height);
    }

    void UltimateWindow::glfeveninfo()const{
        mWindow->glfeveninfo();
    }


    bool UltimateWindow::IsValid() const {
        return mWindow-> IsValid();
    }

    int UltimateWindow::GetHeight() const {
        return mWindow->GetHeight();
    }

    int UltimateWindow::GetWidth() const {
        return mWindow->GetWidth();
    }

    void UltimateWindow::Init() {
        if (!mInstance)
            mInstance = new UltimateWindow;
    }

    UltimateWindow *UltimateWindow::GetWindow() {
        return mInstance;
    }

    void UltimateWindow::Shutdown() {
        if (mInstance)
            delete mInstance;
    }

    void UltimateWindow::SwapBuffers() {
        mWindow->SwapBuffers();
    }

    void UltimateWindow::PollEvents() {
        mWindow->PollEvents();
    }
}
