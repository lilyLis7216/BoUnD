#pragma once
#include "BaseScene.h"
#include "Player.h"

class Game : public BaseScene
{
public:
    Game();
    ~Game();

    void Update() override;
    void Draw()   override;

    static Player* player;
    class FrameRate* frameRate;
    class Background* bg;
    class Acrobat* fo;
    class Collision* coll;

private:
    float deltaTime;
};
