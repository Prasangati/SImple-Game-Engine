#include <iostream>
#include "Ultimate.h"
#include "Player.h"
#include <memory>


class MyGame : public Ultimate::UltimateGame {
public:
    void Initialize() override {
        player = std::make_unique<Player>("Assets/Textures/player.png", 500, 400);
        background = std::make_unique<Ultimate::Image>("Assets/Textures/background.jpg");

        SetKeyPressedCallback([this](const Ultimate::KeyPressed& event) {
            OnKeyPressed(event);
        });
        SetKeyReleasedCallback([this](const Ultimate::KeyReleased& event) {
            OnKeyReleased(event);
        });
    }

    void OnUpdate() override {
        if (movingLeft) {
            player->MoveLeft();
        }
        if (movingRight) {
            player->MoveRight();
        }

        Ultimate::Renderer::Draw(*background, 0, 0);  // Draw background first
        Ultimate::Renderer::Draw(player->GetUnit());  // Draw player on top
    }

    void ShutDown() override {}

private:
    std::unique_ptr<Player> player;
    std::unique_ptr<Ultimate::Image> background;
    bool movingLeft{false};
    bool movingRight{false};

    void OnKeyPressed(const Ultimate::KeyPressed& event) {
        if (event.GetKeyCode() == ULTIMATE_KEY_LEFT) {
            movingLeft = true;
        }
        if (event.GetKeyCode() == ULTIMATE_KEY_RIGHT) {
            movingRight = true;
        }
    }

    void OnKeyReleased(const Ultimate::KeyReleased& event) {
        if (event.GetKeyCode() == ULTIMATE_KEY_LEFT) {
            movingLeft = false;
        }
        if (event.GetKeyCode() == ULTIMATE_KEY_RIGHT) {
            movingRight = false;
        }
    }
};





START_GAME(MyGame)
