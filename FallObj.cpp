#include "FallObj.h"
#include "DxLib.h"

FallObj::FallObj()
{
    posX = 100;
    posY = 540;
    speed = 200.0f;
    isBound = true;
    jumpPower = 0;
    image = LoadGraph("Assets/FallObj/test.png");
}

FallObj::~FallObj()
{
}

void FallObj::Update(float deltaTime)
{
    posX += speed/2 * deltaTime;
    
    if (posY > 980)
    {
        isBound = true;
    }
    else
    {
        isBound = false;
    }
    if (isBound)
    {
        if (jumpPower > 0)
        {
            jumpPower = -15.0f;
        }
    }
    else
    {
        jumpPower += 0.2f;
        if (jumpPower > 30)jumpPower = 30;
    }

    posY += jumpPower;
}

void FallObj::Draw()
{
    DrawRotaGraph((int)posX, (int)posY, scaling, 0, image, FALSE);
}
