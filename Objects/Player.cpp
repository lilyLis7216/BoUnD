#include "Player.h"
#include "DxLib.h"
#include "../Manager/SoundManager.h"
#include "../Append/Controller.h"

Player::Player()
    : life(3)
    , animCount(0)
    , animFrame(0)
    , deltaTime(0)
{
    posX = 960.0f;
    posY = 910.0f;
    scaleX = 120.0f;
    scaleY = 120.0f;
    halfScaleX = scaleX / 2;
    halfScaleY = scaleY / 2;
    speed = 600.0f;
    LoadDivGraph("Assets/Player/player.png", 2, 2, 1, 400, 217, walkAnim);
    image = walkAnim[0];
}

Player::~Player()
{
    // imageの後始末
    DeleteGraph(image);
    
    // walkAnimの後始末
    for (int i = 0; i < 2; i++)
    {
        DeleteGraph(walkAnim[i]);
    }
}

void Player::Update(float deltaTime)
{
    // メンバ変数のdeltaTimeに引数のdeltaTimeを入れる
    this->deltaTime = deltaTime;

    // 移動処理
    Move();

    // 位置調整処理
    AdjustPos();
}

void Player::Draw()
{
    // プレイヤーの描画
    DrawRotaGraph((int)posX, (int)posY, scaling, 0, image, TRUE);
}

void Player::Move()
{
    // 左キーまたはコントローラーの左入力があれば
    if (CheckHitKey(KEY_INPUT_LEFT) || Controller::LeftInput())
    {
        posX -= speed * deltaTime;
        Animation();
    }

    // 右キーまたはコントローラーの右入力があれば
    if (CheckHitKey(KEY_INPUT_RIGHT) || Controller::RightInput())
    {
        posX += speed * deltaTime;
        Animation();
    }
}

void Player::AdjustPos()
{
    // 左の制限まで来たら
    if (posX < 420 + halfScaleX)
    {
        posX = 420 + halfScaleX;

        // 移動制限音を鳴らす
        SoundManager::StartSound(4);
    }

    // 右の制限まで来たら
    if (posX > 1500 - halfScaleX)
    {
        posX = 1500 - halfScaleX;

        // 移動制限音を鳴らす
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
