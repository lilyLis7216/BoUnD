#include "Player.h"
#include "DxLib.h"
#include "../Manager/SoundManager.h"

Player::Player()
    : life(3)
    , animCount(0)
    , animFrame(0)
    , deltaTime(0)
{
    posX = 960.0f;
    posY = 910.0f;
    scaleX = 100.0f;
    scaleY = 50.0f;
    halfScaleX = scaleX / 2;
    halfScaleY = scaleY / 2;
    speed = 600.0f;
    LoadDivGraph("Assets/Player/player.png", 2, 2, 1, 400, 218, walkAnim);
    image = walkAnim[0];
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
        Animation();
    }

    if (CheckHitKey(KEY_INPUT_RIGHT))
    {
        posX += speed * deltaTime;
        Animation();
    }
}

void Player::AdjustPos()
{
    if (posX < 420 + halfScaleX)
    {
        posX = 420 + halfScaleX;
        SoundManager::StartSound(4);
    }

    if (posX > 1500 - halfScaleX)
    {
        posX = 1500 - halfScaleX;
        SoundManager::StartSound(4);
    }
}

void Player::Animation()
{
    animCoolTime -= deltaTime;
    if (animCoolTime <= 0)
    {
        animCount++;
        animCoolTime = 0.2f;
    }
    animFrame = animCount % 2;
    image = walkAnim[animFrame];
}
