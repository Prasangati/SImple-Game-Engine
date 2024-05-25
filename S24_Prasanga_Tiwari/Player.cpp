//
// Created by Prasanga Tiwari on 5/25/24.
//

#include "Player.h"

Player::Player(const std::string& imagePath, int x, int y)
        : Ultimate::Unit(imagePath, x, y) {}

void Player::MoveLeft() {
    UpdateXCoord(-5);
}

void Player::MoveRight() {
    UpdateXCoord(5);
}
