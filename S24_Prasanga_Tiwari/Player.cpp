//
// Created by Prasanga Tiwari on 5/25/24.
//

#include "Player.h"

Player::Player(const std::string& imagePath, int x, int y)
        : mUnit(imagePath, x, y) {}

void Player::MoveLeft() {
    mUnit.UpdateXCoord(-5);
}

void Player::MoveRight() {
    mUnit.UpdateXCoord(5);
}

Ultimate::Unit& Player::GetUnit() {
    return mUnit;
}
