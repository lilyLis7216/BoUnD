#include "Acrobat.h"
#include "DxLib.h"
#include "../Append/Collision.h"
#include "../Manager/GameManager.h"
#include "Player.h"

Acrobat::Acrobat()
    : halfScaleX(scaleX / 2)
    , halfScaleY(scaleY / 2)
    , isBound(false)
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
    scaleX = 75.0f;
    scaleY = 75.0f;
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
    Collision::Coll(player, this);

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

    posY += jumpPower;
    prevHit = nowHit;

    rotate += 0.01f;
}

void Acrobat::Draw()
{
    DrawRotaGraph((int)posX, (int)posY, scaling, rotate, image, TRUE, TRUE);
    //DrawFormatString(0, 140, GetColor(0, 0, 0), "fallObjX:%5.4f", posX);
    //DrawFormatString(0, 160, GetColor(0, 0, 0), "fallObjY:%5.4f", posY);
}

void Acrobat::OnHit(bool flag)
{
    isBound = flag;
    nowHit = true;
    if (!prevHit)
    {
        GameManager::AddScore(100);
        GameManager::AddComb();
        GameManager::AddMaxComb();
    }
}
