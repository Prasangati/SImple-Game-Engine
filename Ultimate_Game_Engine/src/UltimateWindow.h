//
// Created by Prasanga Tiwari on 4/3/24.
//

#ifndef S24_PRASANGA_TIWARI_ULTIMATEWINDOW_H
#define S24_PRASANGA_TIWARI_ULTIMATEWINDOW_H
#include "WindowImpl.h"
#include "utility.h"
#include "pch.h"
namespace Ultimate{
    class ULTIMATE_API UltimateWindow{
    public:
        static void Init();
        static UltimateWindow* GetWindow();
        static void Shutdown();

        void Create(int width, int height);
        int GetWidth() const;
        int GetHeight() const;
        bool IsValid() const;
        void glfeveninfo()const;
    private:
        UltimateWindow();
        inline static UltimateWindow* mInstance{nullptr};
        std::unique_ptr<WindowImpl> mWindow{nullptr};
    };

}




#endif //S24_PRASANGA_TIWARI_ULTIMATEWINDOW_H
