#include "Player.h"
#include "DxLib.h"

Player::Player()
    : life(3)
    , deltaTime(0)
{
    posX = 960.0f;
    posY = 910.0f;
    scaleX = 100.0f;
    scaleY = 50.0f;
    halfScaleX = scaleX / 2;
    halfScaleY = scaleY / 2;
    speed = 600.0f;
    image = LoadGraph("Assets/Player/test.png");
}

Player::~Player()
{
    DeleteGraph(image);
}

void Player::Update(float deltaTime)
{
    this->deltaTime = deltaTime;
    Move();

    AdjustPos();
}

void Player::Draw()
{
    DrawRotaGraph((int)posX, (int)posY, scaling, 0, image, TRUE);
}

void Player::Move()
{
    if (CheckHitKey(KEY_INPUT_LEFT))
    {
        posX -= speed * deltaTime;
    }

    if (CheckHitKey(KEY_INPUT_RIGHT))
    {
        posX += speed * deltaTime;
    }
}

void Player::AdjustPos()
{
    if (posX < 420 + halfScaleX)
    {
        posX = 420 + halfScaleX;
    }

    if (posX > 1500 - halfScaleX)
    {
        posX = 1500 - halfScaleX;
    }
}
