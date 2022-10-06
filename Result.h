#pragma once
#include "BaseScene.h"

class Result : public BaseScene
{
public:
    Result();
    ~Result();

    void Update() override;
    void Draw()   override;
};