#include <iostream>
#include "Ultimate.h"
#include <iostream>
class MyGame: public Ultimate::UltimateGame{
    virtual void Initialize() override{
        my_window.Create(1000,800);
        if (!my_window.IsValid()) {
            std::cerr << "Failed to initialize game window. Info from my game\n";
            exit(EXIT_FAILURE);
        }
    }

    void OnUpdate() override {
        if (!my_window.IsValid()) {
            std::cerr << "Window is not valid.\n";
            return;
        }
        std::cout << "Engine is running...\n";
        my_window.glfeveninfo(); // Ensure you handle the window's events
    }
    void ShutDown() override{
        std::cout << "Shutting down game.\n";
    }
private:
    Ultimate::UltimateWindow my_window;
};

START_GAME(MyGame)
