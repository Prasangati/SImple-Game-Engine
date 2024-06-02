//
// Created by Soleil Rosado on 6/1/24.
//

#include "Lives.h"

Lives::Lives(int life):livesZero(false), lives(life), health("../Assets/Textures/healthy.png"){}



void Lives::DecreaseLife() {
    lives--;
    if (lives == 0){
        livesZero == true;
    }
}

bool Lives::LifeZero() const {
    return livesZero;
}

Ultimate::Image &Lives::getImage()  {
    return health;
}

int Lives::currentLife() const {
    return lives;
}




