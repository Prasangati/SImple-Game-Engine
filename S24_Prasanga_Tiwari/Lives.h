//
// Created by Soleil Rosado on 6/1/24.
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

    bool LifeZero() const;


private:
    bool livesZero;
    int lives;
    Ultimate::Image health;
};


#endif //PRASANGA_GAME_LIVES_H
