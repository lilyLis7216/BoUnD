#pragma once
#include "BaseObject.h"

class FallObj : public BaseObject
{
public:
    FallObj();
    ~FallObj();

    void Update(float deltaTime) override;
    void Draw() override;

    float GetPosX() const { return posX; }
    float GetPosY() const { return posY; }

private:
    //! ‘¬“x
    float speed;

    bool isBound;

    float jumpPower;
};