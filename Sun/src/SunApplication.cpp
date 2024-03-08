//
// Created by Prasanga Tiwari on 3/3/24.
//
#include "pch.h"
#include "SunApplication.h"

namespace Sun{

    void SunApplication::initialize() {
    }

    void SunApplication::OnUpdate() {

    }

    void SunApplication::ShutDown() {

    }

    void SunApplication::Run() {
        initialize();
        while (true){
            OnUpdate();
        }
        ShutDown();
    }
}