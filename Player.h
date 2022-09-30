#pragma once
#include "BaseObject.h"

class Player : public BaseObject
{
public:
    Player();
    ~Player();

    void Update() override;
    void Draw()   override;

private:
    void Move();

    //! Žc‹@
    int life;
};