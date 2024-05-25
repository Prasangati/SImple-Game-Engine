//
// Created by Prasanga Tiwari on 5/24/24.
//

#ifndef YOURPROJECTNAME_ULTIMATEEVENTS_H
#define YOURPROJECTNAME_ULTIMATEEVENTS_H
#include "utility.h"
#include "pch.h"

namespace Ultimate{
    class ULTIMATE_API KeyPressed{
    public:
        KeyPressed(int kCode);
        int GetKeyCode() const;
    private:
        int mKeyCode;
    };

    class ULTIMATE_API KeyReleased{
    public:
        KeyReleased(int kCode);
        int GetKeyCode() const;
    private:
        int mKeyCode;
    };
}

#endif //YOURPROJECTNAME_ULTIMATEEVENTS_H
