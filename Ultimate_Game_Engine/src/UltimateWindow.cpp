//
// Created by Prasanga Tiwari on 4/3/24.
//
#include "pch.h"
#include "UltimateWindow.h"

namespace Ultimate
{
    void UltimateWindow::Create(int width, int height){
        mWindow -> Create(width, height);
    }
    int UltimateWindow::GetHeight() const {
        return mWindow->GetHeight();
    }
    int UltimateWindow::GetWidth() const {
        return mWindow->GetWidth();
    }
}