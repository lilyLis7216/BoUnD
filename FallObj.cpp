#include "FallObj.h"
#include "DxLib.h"

FallObj::FallObj()
{
    posX = 100;
    posY = 100;
    speed = 200.0f;
    image = LoadGraph("Assets/FallObj/test.png");
}

FallObj::~FallObj()
{
}

void FallObj::Update(float deltaTime)
{
    posY += speed * deltaTime;
}

void FallObj::Draw()
{
    DrawRotaGraph((int)posX, (int)posY, scaling, 0, image, FALSE);
}
