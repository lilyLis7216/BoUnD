#pragma once
#include "BaseObject.h"

class FallObj : public BaseObject
{
public:
    FallObj();
    ~FallObj();

    void Update(float deltaTime) override;
    void Draw() override;

    float GetPosY() const { return posY; }

private:
    //! ‘¬“x
    float speed;
};