//
// Created by Soleil Rosado on 6/1/24.
//

#include "Lives.h"

Lives::Lives(int life):lives(life), health("../Assets/Textures/healthy.png"){}



void Lives::DecreaseLife() {
    lives--;
}

bool Lives::lifeNotZero() const {
    return lives>0;
}

Ultimate::Image &Lives::getImage()  {
    return health;
}

int Lives::currentLife() const {
    return lives;
}




