#pragma once
#include "BaseObject.h"

class Player : public BaseObject
{
public:
    Player();
    ~Player();

    void Update(float deltaTime) override;
    void Draw() override;

    float GetHalfScaleX() const { return halfScaleX; }
    float GetHalfScaleY() const { return halfScaleY; }

private:
    void Move(float deltaTime);

    void AdjustPos();

    //! �����̔���
    float halfScaleX;
    //! �c���̔���
    float halfScaleY;

    //! �c�@
    int life;

    //! ���x
    float speed;

};
