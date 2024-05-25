#include "Ultimate.h"
#include "Player.h"

#include <iostream>
#include <filesystem> // C++17

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

        Ultimate::Renderer::GetInstance()->Draw(player->GetUnit());
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

int main() {
    std::cout << "Current working directory: " << std::filesystem::current_path() << std::endl;

    MyGame game;
    game.Run();

    return 0;
}


