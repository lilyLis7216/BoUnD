#include "Player.h"
#include "DxLib.h"

//--------------------------------------------------------------------------------------------------------------------------------
// @brief コンストラクタ
//--------------------------------------------------------------------------------------------------------------------------------
Player::Player()
    :life(3)
{
    posX = 1920 / 2;
    posY = 1080 * 3 / 4;
    scaleX = 100.0f;
    scaleY = 100.0f;
    image = LoadGraph("Assets/Player/test.png");
}

//--------------------------------------------------------------------------------------------------------------------------------
// @brief デストラクタ
//--------------------------------------------------------------------------------------------------------------------------------
Player::~Player()
{
}

//--------------------------------------------------------------------------------------------------------------------------------
// @brief プレイヤー更新処理
//--------------------------------------------------------------------------------------------------------------------------------
void Player::Update()
{
    Move();
}

//--------------------------------------------------------------------------------------------------------------------------------
// @brief プレイヤー描画処理
//--------------------------------------------------------------------------------------------------------------------------------
void Player::Draw()
{
    DrawRotaGraph((int)posX, (int)posY, scaling, 0, image, FALSE);
}

//--------------------------------------------------------------------------------------------------------------------------------
// @brief プレイヤー移動処理
//--------------------------------------------------------------------------------------------------------------------------------
void Player::Move()
{
    if (CheckHitKey(KEY_INPUT_LEFT))
    {
        posX--;
    }

    if (CheckHitKey(KEY_INPUT_RIGHT))
    {
        posX++;
    }
}
