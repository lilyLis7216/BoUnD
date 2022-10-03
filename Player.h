#pragma once
#include "BaseObject.h"

class Player : public BaseObject
{
public:
    Player();
    ~Player();

    void Update(float deltaTime) override;
    void Draw()   override;

private:
    void Move(float deltaTime);

    void AdjustPos();

    //! ‰¡•‚Ì”¼•ª
    float halfScaleX;
    //! c•‚Ì”¼•ª
    float halfScaleY;

    //! c‹@
    int life;

    //! ‘¬“x
    float speed;

};