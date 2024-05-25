//
// Created by Prasanga Tiwari on 3/3/24.
//

#ifndef S24_PRASANGA_TIWARI_SUNAPPLICATION_H
#define S24_PRASANGA_TIWARI_SUNAPPLICATION_H
#include "pch.h"
#include "utility.h"
#include "UltimateEvents.h"
constexpr int ULTIMATE_FRAME_RATE{60};
namespace Ultimate {
    class  UltimateGame {
    public:
        virtual void Initialize();
        virtual void OnUpdate();
        virtual void ShutDown();

        void Run();

        void SetKeyPressedCallback(const std::function<void(const KeyPressed&)>& callbackFunc);
        void SetKeyReleasedCallback(const std::function<void(const KeyReleased&)>& callbackFunc);
        void SetWindowCloseCallback(const std::function<void()>& callbackFunc);



    private:
        std::chrono::steady_clock::time_point mNextFrameTime;
        std::chrono::milliseconds mFrameDuration{1000 / ULTIMATE_FRAME_RATE};
    };


}



#endif //S24_PRASANGA_TIWARI_SUNAPPLICATION_H
