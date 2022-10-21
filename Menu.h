#pragma once
#include "BaseScene.h"

class Menu : public BaseScene
{
public:
    Menu();
    ~Menu();

    void Update() override;
    void Draw()   override;

private:
    int logo;
    int enterImage;
};
