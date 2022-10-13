#pragma once
#include "BaseScene.h"

class Background;
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

private:
    FrameRate* frameRate;
    Background* bg;
    Player* player;
    Collision* coll;
    float deltaTime;
};
