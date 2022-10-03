#pragma once
#include "BaseObject.h"

class Background : public BaseObject
{
public:
    Background();
    ~Background();

    void Update(float deltaTime) override;
    void Draw() override;

private:

};