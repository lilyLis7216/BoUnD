#pragma once
#include "BaseObject.h"

class FallObj : public BaseObject
{
public:
    FallObj();
    ~FallObj();

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
};
