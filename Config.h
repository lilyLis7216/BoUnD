#pragma once
#include "BaseScene.h"

class Config : public BaseScene
{
public:
    Config();
    ~Config();

    void Update() override;
    void Draw()   override;

};