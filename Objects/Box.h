#pragma once
#include "../BaseClass/BaseObject.h"

class Box : public BaseObject
{
public:
    Box();

    ~Box();

    void Update(float deltaTime) override;

    void Draw() override;


};