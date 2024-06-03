//
// Created by Prasanga Tiwari on 4/3/24.
//

#ifndef S24_PRASANGA_TIWARI_ULTIMATEWINDOW_H
#define S24_PRASANGA_TIWARI_ULTIMATEWINDOW_H
#include "pch.h"
#include "WindowImpl.h"
#include "utility.h"
#include "UltimateEvents.h"
namespace Ultimate{
    class ULTIMATE_API UltimateWindow{
    public:
        static void Init();
        static UltimateWindow* GetWindow();
        static void Shutdown();

        void SwapBuffers();
        void PollEvents();
        void Create(int width, int height);
        int GetWidth() const;
        int GetHeight() const;
        bool IsValid() const;
        void glfeveninfo()const;

        void SetKeyPressedCallback(std::function<void(const KeyPressed&)> callbackFunc);
        void SetKeyReleasedCallback(std::function<void(const KeyReleased&)> callbackFunc);
        void SetWindowCloseCallback(std::function<void()> callbackFunc);

    private:
        UltimateWindow();
        inline static UltimateWindow* mInstance{nullptr};
        std::unique_ptr<WindowImpl> mWindow{nullptr};
    };

}




#endif //S24_PRASANGA_TIWARI_ULTIMATEWINDOW_H
