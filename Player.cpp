#include "Player.h"
#include "DxLib.h"

//--------------------------------------------------------------------------------------------------------------------------------
// @brief コンストラクタ
//--------------------------------------------------------------------------------------------------------------------------------
Player::Player()
    :life(3)
{
    posX = 960.0f;
    posY = 910.0f;
    scaleX = 100.0f;
    scaleY = 25.0f;
    halfScaleX = scaleX / 2;
    halfScaleY = scaleY / 2;
    speed = 200.0f;
    image = LoadGraph("Assets/Player/test.png");
}

//--------------------------------------------------------------------------------------------------------------------------------
// @brief デストラクタ
//--------------------------------------------------------------------------------------------------------------------------------
Player::~Player()
{
    DeleteGraph(image);
}

//--------------------------------------------------------------------------------------------------------------------------------
// @brief プレイヤー更新処理
//--------------------------------------------------------------------------------------------------------------------------------
void Player::Update(float deltaTime)
{
    Move(deltaTime);

    AdjustPos();
}

//--------------------------------------------------------------------------------------------------------------------------------
// @brief プレイヤー描画処理
//--------------------------------------------------------------------------------------------------------------------------------
void Player::Draw()
{
    DrawRotaGraph((int)posX, (int)posY, scaling, 0, image, TRUE);
}

//--------------------------------------------------------------------------------------------------------------------------------
// @brief プレイヤー移動処理
//--------------------------------------------------------------------------------------------------------------------------------
void Player::Move(float deltaTime)
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

//--------------------------------------------------------------------------------------------------------------------------------
// @brief プレイヤー位置修正処理
//--------------------------------------------------------------------------------------------------------------------------------
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
