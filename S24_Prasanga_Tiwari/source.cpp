#include <iostream>
#include "Ultimate.h"
#include <iostream>
class MyGame: public Ultimate::UltimateGame{
    virtual void Initialize() override{
        my_window.Create(1000,800);
    }

    void OnUpdate() override {
        std::cout<<"engine is running"<<std::endl;
    }
    void ShutDown() override{
    }
private:
    Ultimate::UltimateWindow my_window;
};

START_GAME(MyGame)
