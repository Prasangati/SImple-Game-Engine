#include <iostream>
#include "sun.h"
#include <iostream>
class MyGame: public Sun::SunApplication{
    void initialize() override{
    }
    void OnUpdate() override {
        std::cout<<"engine is running"<<std::endl;
    }
    void ShutDown() override{
    }
};

START_GAME(MyGame)
