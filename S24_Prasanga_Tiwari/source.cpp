#include <iostream>
#include "Ultimate.h"
#include <iostream>
class MyGame: public Ultimate::UltimateGame{
    void initialize() override{
    }
    void OnUpdate() override {
        std::cout<<"engine is running"<<std::endl;
    }
    void ShutDown() override{
    }
};

START_GAME(MyGame)
