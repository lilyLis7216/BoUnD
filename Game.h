#pragma once
#include "BaseScene.h"

class FrameRate;
class Player;
class Collision;

class Game : public BaseScene
{
public:
    Game();
    ~Game();

    void Update() override;
    void Draw()   override;

    void UI();

private:
    FrameRate* frameRate;
    Player* player;
    Collision* coll;
    float deltaTime;
};
