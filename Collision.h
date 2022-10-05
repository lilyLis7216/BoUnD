#pragma once

class Player;
class FallObj;

class Collision
{
public:
    Collision();
    ~Collision();

    void Coll(float aPosX, float aPosY, float aScaleX, float aScaleY,
              float bPosX, float bPosY, float bScaleX, float bScaleY);

    void Coll(Player* player, FallObj* fallObj);

private:
};
