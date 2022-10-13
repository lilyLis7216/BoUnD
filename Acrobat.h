#pragma once
#include "BaseObject.h"

class Player;

class Acrobat : public BaseObject
{
public:
    Acrobat();
    ~Acrobat();

    void Update(float deltaTime) override;
    void Update(float deltaTime, Player* player);
    void Draw() override;

    float GetHalfScaleX() const { return halfScaleX; }
    float GetHalfScaleY() const { return halfScaleY; }

    void SetBound(bool flag);

private:
    //! ‘¬“x
    float speed;

    bool isBound;

    float jumpPower;

    float halfScaleX;
    float halfScaleY;

    int tmpCount;
};
