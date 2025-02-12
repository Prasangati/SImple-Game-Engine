//
// Created by Prasanga Tiwari on 5/4/24.
//

#include "MyGame.h"


MyGame::MyGame()
    :background("../Assets/Textures/background.png"),
    bucket("../Assets/Textures/Bucket.png",450,0), apple("../Assets/Textures/apple.png", 0,600), gameLife(3)
     {}



void MyGame::Initialize() {
    SetKeyPressedCallback([this](const Ultimate:: KeyPressed& event) {
        OnKeyPressed (event) ;
    }) ;
    SetKeyReleasedCallback([this](const Ultimate:: KeyReleased& event) {
        OnKeyReleased (event) ;
    }) ;
    std::srand(std::time(0));
}

void MyGame::OnUpdate() {
    Ultimate::Renderer::Draw(background, 0, 0);
    if (gameLife.lifeNotZero()){
        int current = 0;
        int x = 5;
        int y = 520;
        while (current < gameLife.currentLife()){
            Ultimate::Renderer::Draw(gameLife.getImage(),x,y);
            current ++;
            x += 60;
        }
        if (noAppleDropping){
            int random_number = std::rand() % 1000; // Generates a number between 0 and 999
            apple.UpdateXCoord(-apple.GetXCoord());
            apple.UpdateXCoord(random_number);
            apple.UpdateYCoord(600-apple.GetYCoord());
            noAppleDropping = false;
        }
        else if (apple.GetYCoord() < 120 && Ultimate::UnitsOverlap(apple,bucket.GetUnit())){
            score ++;
            noAppleDropping = true;
            applesleft --;
        }
        else if (apple.GetYCoord() < 120 && !(Ultimate::UnitsOverlap(apple, bucket.GetUnit()))){
            noAppleDropping = true;
            gameLife.DecreaseLife();
            applesleft --;

        }
        else{
            apple.UpdateYCoord(-8);
        }
        Ultimate::Renderer::Draw(apple);

        if (movingRight){
            bucket.MoveRight();
        }
        if (movingLeft){
            bucket.MoveLeft();
        }
    }
    else{
        Ultimate::Renderer::Draw(yourscore,200,280);

        int startX = 175;
        int y = 85;
        int digitWidth = 80; //pixels between the digits

        std::string scoreStr = std::to_string(score);
        for (char digitChar : scoreStr) {
            int digit = digitChar - '0';
            Ultimate::Image image(imagePaths[digit]);
            Ultimate::Renderer::Draw(image, startX, y);
            startX += digitWidth; // Move to the next position
        }
    }






    Ultimate::Renderer::Draw(bucket.GetUnit());





    //Ultimate::Unit anotherapple("../Assets/Textures/apple.png", 465,105);
    //Ultimate::Renderer::Draw(anotherapple);
}


