//
// Created by Prasanga Tiwari on 5/25/24.
//

#ifndef YOURPROJECTNAME_PLAYER_H
#define YOURPROJECTNAME_PLAYER_H

#include "Ultimate.h"

class Player : public Ultimate::Unit {
public:
    Player(const std::string& imagePath, int x, int y);
    void MoveLeft();
    void MoveRight();
};


#endif //YOURPROJECTNAME_PLAYER_H
