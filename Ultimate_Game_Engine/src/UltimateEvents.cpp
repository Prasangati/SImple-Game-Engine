//
// Created by Prasanga Tiwari on 5/24/24.
//

#include "UltimateEvents.h"
namespace Ultimate{
    KeyPressed::KeyPressed(int kCode):mKeyCode(kCode) {}

    int KeyPressed::GetKeyCode() const {
        return mKeyCode;
    }

    KeyReleased::KeyReleased(int kCode): mKeyCode(kCode) {
    }

    int KeyReleased::GetKeyCode() const {
        return mKeyCode;
    }


}