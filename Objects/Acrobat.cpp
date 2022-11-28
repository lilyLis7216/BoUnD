#include "Acrobat.h"
#include "DxLib.h"
#include "../Append/Collision.h"
#include "../Manager/GameManager.h"
#include "../Manager/SoundManager.h"
#include "Player.h"
#include "Box.h"

Acrobat::Acrobat(float x)
    : isBound(false)
    , jumpPower(-7.5f)
    , nowHit(false)
    , prevHit(false)
    , animCount(0)
    , animCoolTime(0)
    , animFrame(0)
    , deltaTime(0)
    , isMove(true)
    , isMiss(false)
    , isDead(false)
    , vanishTime(3.0f)
    , resetCombPrevCall(false)
{
    posX = x;
    posY = -100.0f;
    scaleX = 40.0f;
    scaleY = 120.0f;
    halfScaleX = scaleX / 2;
    halfScaleY = scaleY / 2;
    speed = 200.0f;
    LoadDivGraph("Assets/Acrobat/acrobatWalkAnim.png", 2, 2, 1, 86, 134, walkAnim);
    LoadDivGraph("Assets/Acrobat/acrobatSuccessAnim.png", 2, 2, 1, 86, 150, successAnim);
    missGraph = LoadGraph("Assets/Acrobat/miss.png");
    image = walkAnim[0];
    rotate = (float)GetRand(3);
}

Acrobat::~Acrobat()
{
    // imageの後始末
    image = -1;

    // walkAnimの後始末
    for (int i = 0; i < 2; i++)
    {
        DeleteGraph(walkAnim[i]);
    }
}

void Acrobat::Update(float deltaTime, Player* player, Box* box)
{
    // メンバ変数のdeltaTimeに引数のdeltaTimeを入れる
    this->deltaTime = deltaTime;

    if (isMove)
    {
        // 移動処理
        Move();

        // 毎フレーム回転に加算する
        rotate += 0.01f;

        // プレイヤーとの当たり判定
        Collision::CollPtoA(player, this);
    }
    else
    {
        vanishTime -= deltaTime;

        if (vanishTime < 0)
        {
            isDead = true;
        }

        rotate = 0.0f;
    }

    // アニメーション
    Animation();

    // 箱との当たり判定
    Collision::CollBtoA(box, this);

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

        // 跳ねるサウンドを鳴らす
        SoundManager::StartSound(5);
    }
}

void Acrobat::boxHit()
{
    // 動かない状態にする
    isMove = false;

    // スコアを500増やす
    if (!prevHit)
    {
        GameManager::AddScore(500);
        SoundManager::StartSound(7);
        nowHit = true;
    }
}

void Acrobat::Move()
{
    posX += speed * deltaTime;

    if (posY < 835 || 935 < posY)
    {
        isBound = false;
        nowHit = false;
    }

    if (isBound)
    {
        jumpPower = -15.0f;
    }
    else
    {
        jumpPower += 0.2f;
        if (jumpPower > 30)jumpPower = 30;
    }

    if (posY > 935)
    {
        isMove = false;
        isMiss = true;
        if (!resetCombPrevCall)
        {
            GameManager::ResetComb();
            SoundManager::StartSound(6);
            resetCombPrevCall = true;
        }
    }

    // y軸にジャンプパワーを加算する
    posY += jumpPower;
}

void Acrobat::Animation()
{
    animCoolTime -= deltaTime;

    if (animCoolTime <= 0)
    {
        animCount++;

        animCoolTime = 0.5f;
    }

    animFrame = animCount % 2;

    if (isMove)
    {
        image = walkAnim[animFrame];
    }
    else
    {
        if (isMiss)
        {
            image = missGraph;
        }
        else
        {
            image = successAnim[animFrame];
        }
    }
}
