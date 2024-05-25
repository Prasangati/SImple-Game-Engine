//
// Created by Prasanga Tiwari on 5/25/24.
//

#ifndef PLAYER_H
#define PLAYER_H

#include "Ultimate.h"

class Player {
public:
    Player(const std::string& imagePath, int x, int y);
    void MoveLeft();
    void MoveRight();
    Ultimate::Unit& GetUnit();

private:
    Ultimate::Unit mUnit;
};

#endif // PLAYER_H
