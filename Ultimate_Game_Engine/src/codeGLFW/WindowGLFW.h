//
// Created by Prasanga Tiwari on 4/3/24.
//

#ifndef S24_PRASANGA_TIWARI_WINDOWGLFW_H
#define S24_PRASANGA_TIWARI_WINDOWGLFW_H
#include "../WindowImpl.h"

namespace Ultimate {

    class WindowGLFW : public WindowImpl {
    public:
        WindowGLW();
        virtual void Create(int width, int height) override;
        virtual int GetWidth() const override;
        virtual int GetHeight() const override;
        ~WindowGLW();

    private:
        GLFWwindow* mWindow(nullptr);
    };

} // Ultimate

#endif //S24_PRASANGA_TIWARI_WINDOWGLFW_H
