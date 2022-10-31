#include "Box.h"
#include "DxLib.h"

Box::Box()
{
    posX = 1690.0f;
    posY = 720.0f;
    scaleX = 420.0f;
    scaleY = 344.0f;
    halfScaleX = scaleX / 2;
    halfScaleY = scaleY / 2;
    image = LoadGraph("Assets/Item/box.png");
}

Box::~Box()
{
    DeleteGraph(image);
}

void Box::Update(float deltaTime)
{
}

void Box::Draw()
{
    // ” ‚Ì•`‰æ
    DrawRotaGraph((int)posX, (int)posY, 1.0f, 0, image, TRUE);
}
