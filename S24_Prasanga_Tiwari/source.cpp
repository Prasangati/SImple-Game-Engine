#include <iostream>
#include "Ultimate.h"
#include <iostream>
class MyGame: public Ultimate::UltimateGame{
    virtual void Initialize() override{

    }

    void OnUpdate() override {
        std::cout << "Window width: " << Ultimate::UltimateWindow::GetWindow()->GetWidth()<<std::endl;
        //my_window.glfeveninfo(); // Ensure you handle the window's events
    }
    void ShutDown() override{
        std::cout << "Shutting down game.\n";
    }

};

START_GAME(MyGame)
