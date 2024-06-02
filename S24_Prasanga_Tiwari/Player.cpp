//
// Created by Prasanga Tiwari on 5/25/24.
//
#include "Player.h"

Player::Player(const std::string& imagePath, int x, int y)
        : mUnit(imagePath, x, y) {}

void Player::MoveLeft() {
    if (mUnit.GetXCoord()-10 > -5)
        mUnit.UpdateXCoord(-15);
}

void Player::MoveRight() {
    if (mUnit.GetXCoord()+10 < 956)
        mUnit.UpdateXCoord(15);
}

Ultimate::Unit& Player::GetUnit() {
    return mUnit;
}
