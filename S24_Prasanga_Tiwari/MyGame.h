//
// Created by Prasanga Tiwari on 5/31/24.
//

#ifndef PRASANGA_GAME_MYGAME_H
#define PRASANGA_GAME_MYGAME_H
#include "Ultimate.h"
#include "Player.h"
#include "Lives.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <string>
class MyGame : public Ultimate::UltimateGame {
public:
    MyGame();
    virtual void Initialize() override;

    virtual void OnUpdate() override;


private:

    Ultimate::Image background;
    Player bucket;
    Ultimate::Unit apple;
    Lives gameLife;
    Ultimate::Image yourscore{"../Assets/Textures/Drawing.png"};

    int applesleft{10};
    int score{0};
    std::vector<std::string> imagePaths = {
            "../Assets/Textures/Drawing-0.png",
            "../Assets/Textures/Drawing-1.png",
            "../Assets/Textures/Drawing-2.png",
            "../Assets/Textures/Drawing-3.png",
            "../Assets/Textures/Drawing-4.png",
            "../Assets/Textures/Drawing-5.png",
            "../Assets/Textures/Drawing-6.png",
            "../Assets/Textures/Drawing-7.png",
            "../Assets/Textures/Drawing-8.png",
            "../Assets/Textures/Drawing-9.png"
    };





    bool movingLeft{false};
    bool movingRight{false};


    bool noAppleDropping{true};

    void OnKeyPressed(const Ultimate::KeyPressed& event) {
        if (event.GetKeyCode() == ULTIMATE_KEY_LEFT) {
            movingLeft = true;
        }
        if (event.GetKeyCode() == ULTIMATE_KEY_RIGHT) {
            movingRight = true;
        }
    }

    void OnKeyReleased(const Ultimate::KeyReleased& event) {
        if (event.GetKeyCode() == ULTIMATE_KEY_LEFT) {
            movingLeft = false;
        }
        if (event.GetKeyCode() == ULTIMATE_KEY_RIGHT) {
            movingRight = false;
        }
    }
};


#endif //PRASANGA_GAME_MYGAME_H
