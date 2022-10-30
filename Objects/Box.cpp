#include "Box.h"
#include "DxLib.h"

Box::Box()
{
    posX = 1690.0f;
    posY = 850.0f;
    scaleX = 420.0f;
    scaleY = 344.0f;
    halfScaleX = scaleX / 2;
    halfScaleY = scaleY / 2;
    image = LoadGraph("Assets/Item/box.png");
}

Box::~Box()
{
}

void Box::Update(float deltaTime)
{
}

void Box::Draw()
{
    // ���̕`��
    DrawRotaGraph((int)posX, (int)posY, 1.0f, 0, image, TRUE);
}
