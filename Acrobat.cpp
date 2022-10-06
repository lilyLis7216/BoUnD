#include "Acrobat.h"
#include "DxLib.h"

Acrobat::Acrobat()
{
    posX = 300;
    posY = 200;
    scaleX = 100.0f;
    scaleY = 100.0f;
    halfScaleX = scaleX / 2;
    halfScaleY = scaleY / 2;
    speed = 200.0f;
    isBound = false;
    jumpPower = 0;
    tmpCount = 0;
    image = LoadGraph("Assets/Acrobat/test.png");
}

Acrobat::~Acrobat()
{
}

void Acrobat::Update(float deltaTime)
{
    posX += speed * deltaTime;
    
    if (posY > 980)
    {
        //isBound = true;
    }
    else
    {
        isBound = false;
    }
    if (isBound)
    {
        /*if (jumpPower > 0)
        {
        }*/
        jumpPower = -15.0f;
    }
    else
    {
        jumpPower += 0.2f;
        if (jumpPower > 30)jumpPower = 30;
    }

    posY += jumpPower;
}

void Acrobat::Draw()
{
    DrawRotaGraph((int)posX, (int)posY, scaling, 0, image, FALSE);
    DrawFormatString(0, 140, GetColor(0, 0, 0), "fallObjX:%5.4f", posX);
    DrawFormatString(0, 160, GetColor(0, 0, 0), "fallObjY:%5.4f", posY);
}

void Acrobat::OnHit(bool flag)
{
    isBound = flag;
}
