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
