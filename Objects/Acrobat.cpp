#include "Acrobat.h"
#include "DxLib.h"
#include "../Append/Collision.h"
#include "../Manager/GameManager.h"
#include "Player.h"

Acrobat::Acrobat()
    : isBound(false)
    , jumpPower(-7.5f)
    , nowHit(false)
    , prevHit(false)
    , animCount(0)
    , animCoolTime(0)
    , animFrame(0)
    , deltaTime(0)
{
    posX = 300;
    posY = 200;
    scaleX = 60.0f;
    scaleY = 120.0f;
    halfScaleX = scaleX / 2;
    halfScaleY = scaleY / 2;
    speed = 200.0f;
    //LoadDivGraph("Assets/Acrobat/acrobat.png", 2, 2, 1, 150, 150, walkAnim);
    image = LoadGraph("Assets/Acrobat/acrobat1.png");
    rotate = (float)GetRand(3);
}

Acrobat::~Acrobat()
{
}

void Acrobat::Update(float deltaTime, Player* player)
{


    posX += speed * deltaTime;
    
    if (posY < 835 || 935 < posY)
    {
        isBound = false;
        nowHit = false;
    }

    float tmp = (float)GetRand(5) + 10;
    if (isBound)
    {
        jumpPower = -tmp;
    }
    else
    {
        jumpPower += 0.2f;
        if (jumpPower > 30)jumpPower = 30;
    }

    // y軸にジャンプパワーを加算する
    posY += jumpPower;

    // 毎フレーム回転に加算する
    rotate += 0.01f;

    //Collision::Coll(player, this);
    Collision::Test(player, this);

    // ヒットしたかどうかを保存する
    prevHit = nowHit;
}

void Acrobat::Draw()
{
    // アクロバットを描画する
    DrawRotaGraph((int)posX, (int)posY, scaling, rotate, image, TRUE, TRUE);

    // デバッグ用座標表示
    //DrawFormatString(0, 140, GetColor(0, 0, 0), "fallObjX:%5.4f", posX);
    //DrawFormatString(0, 160, GetColor(0, 0, 0), "fallObjY:%5.4f", posY);
}

void Acrobat::OnHit()
{
    // バウンドフラグを立てる
    isBound = true;

    // 当たっている状態を保存する
    nowHit = true;

    // 前のフレーム当たっていなければ
    if (!prevHit)
    {
        // スコアを100増やす
        GameManager::AddScore(100);

        // コンボを増やす
        GameManager::AddComb();

        // 最大コンボ数を増やす
        GameManager::AddMaxComb();
    }
}
