#pragma once
#include "BaseObject.h"

class Acrobat : public BaseObject
{
public:
    Acrobat();
    ~Acrobat();

    void Update(float deltaTime) override;
    void Draw() override;

    float GetHalfScaleX() const { return halfScaleX; }
    float GetHalfScaleY() const { return halfScaleY; }

    void OnHit(bool flag) { isBound = flag; }

private:
    //! ‘¬“x
    float speed;

    bool isBound;

    float jumpPower;

    float halfScaleX;
    float halfScaleY;

    int tmpCount;
};
