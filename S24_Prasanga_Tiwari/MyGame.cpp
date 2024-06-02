//
// Created by Soleil Rosado on 5/31/24.
//

#include "MyGame.h"


MyGame::MyGame()
    :background("../Assets/Textures/background.png"),
    bucket("../Assets/Textures/Bucket.png",955,0), apple("../Assets/Textures/apple.png", 0,600), gameLife(3)
     {}



void MyGame::Initialize() {
    SetKeyPressedCallback([this](const Ultimate:: KeyPressed& event) {
        OnKeyPressed (event) ;
    }) ;
    SetKeyReleasedCallback([this](const Ultimate:: KeyReleased& event) {
        OnKeyReleased (event) ;
    }) ;
}

void MyGame::OnUpdate() {
    Ultimate::Renderer::Draw(background, 0, 0);
    if (!(gameLife.LifeZero())){
        int current = 0;
        int x = 5;
        int y = 520;
        while (current < gameLife.currentLife()){
            Ultimate::Renderer::Draw(gameLife.getImage(),x,y);
            current ++;
            x += 50;
        }
        if (noAppleDropping){
            std::srand(std::time(0)); // Seed the random number generator
            int random_number = std::rand() % 1000; // Generates a number between 0 and 999
            apple.UpdateXCoord(apple.GetXCoord()-apple.GetXCoord()+random_number);
            apple.UpdateYCoord(600-apple.GetYCoord());
            noAppleDropping = false;
        }
        else
            apple.UpdateYCoord(-20);


    }

    if (movingRight){
        bucket.MoveRight();
    }
    if (movingLeft){
        bucket.MoveLeft();
    }
    Ultimate::Renderer::Draw(bucket.GetUnit());
    Ultimate::Renderer::Draw(apple);


}


