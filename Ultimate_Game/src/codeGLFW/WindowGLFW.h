//
// Created by Prasanga Tiwari on 4/3/24.
//

#ifndef S24_PRASANGA_TIWARI_WINDOWGLFW_H
#define S24_PRASANGA_TIWARI_WINDOWGLFW_H
#include "pch.h"
#include "../WindowImpl.h"
#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "UltimateEvents.h"

namespace Ultimate {

    class WindowGLFW : public WindowImpl {
    public:
        WindowGLFW();
        virtual void Create(int width, int height) override;
        virtual void SwapBuffers() override;
        virtual void PollEvents() override;
        virtual int GetWidth() const override;
        virtual int GetHeight() const override;
        virtual bool IsValid() const override;
        virtual void glfeveninfo() const override;

        virtual void SetKeyPressedCallback(std::function<void(const KeyPressed&)> callbackFunc) override;
        virtual void SetKeyReleasedCallback(std::function<void(const KeyReleased&)> callbackFunc) override;
        virtual void SetWindowCloseCallback(std::function<void()> callbackFunc) override;

        ~WindowGLFW() override;

    private:
        struct Callbacks {
            std::function<void(const KeyPressed&)> keyPressedFunc{ [] (const KeyPressed&){} };
            std::function<void(const KeyReleased&)> keyReleasedFunc{ [] (const KeyReleased&){} };
            std::function<void()> windowCloseFunc{ [] () {} };
        } mCallbacks;

        GLFWwindow* mWindow{ nullptr };
    };

}

#endif //S24_PRASANGA_TIWARI_WINDOWGLFW_H
