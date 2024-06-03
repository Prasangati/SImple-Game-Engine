//
// Created by Prasanga Tiwari on 5/4/24.
//

#ifndef PRASANGA_GAME_LIVES_H
#define PRASANGA_GAME_LIVES_H
#include "Ultimate.h"

class Lives {
public:
    Lives(int life);

    void DecreaseLife();

    int currentLife()const;

    Ultimate::Image& getImage();

    bool lifeNotZero() const;


private:
    int lives;
    Ultimate::Image health;
};


#endif //PRASANGA_GAME_LIVES_H
