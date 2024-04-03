//
// Created by Prasanga Tiwari on 4/3/24.
//

#ifndef S24_PRASANGA_TIWARI_ULTIMATEWINDOW_H
#define S24_PRASANGA_TIWARI_ULTIMATEWINDOW_H
#include "WindowImpl.h"
namespace Ultimate{
    class UltimateWindow{
    public:
        void Create(int width, int height);
        int GetWidth() const;
        int GetHeight() const;

    private:
        WindowImpl* mWindow(nullptr);
    };

}




#endif //S24_PRASANGA_TIWARI_ULTIMATEWINDOW_H
