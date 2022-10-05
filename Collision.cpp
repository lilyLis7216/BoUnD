#include "Collision.h"
#include "Player.h"
#include "FallObj.h"
#include "DxLib.h"

Collision::Collision()
{
}

Collision::~Collision()
{
}

void Collision::Coll(float aPosX, float aPosY, float aScaleX, float aScaleY, float bPosX, float bPosY, float bScaleX, float bScaleY)
{
    if ((aPosX + aScaleX < bPosX - bScaleX) || (aPosX - aScaleX > bPosX + bScaleX) &&
        (aPosY + aScaleY < bPosY - aScaleY) || (aPosY - aScaleY > bPosY + bScaleY))
    {
        // �������Ă��Ȃ�
    }
}

void Collision::Coll(Player* player, FallObj* fallObj)
{
    if (((player->GetPosX() + player->GetHalfScaleX() < fallObj->GetPosX() - fallObj->GetHalfScaleX()) || (player->GetPosX() - player->GetHalfScaleX() > fallObj->GetPosX() + fallObj->GetHalfScaleX())) &&
        ((player->GetPosY() + player->GetHalfScaleY() < fallObj->GetPosY() - fallObj->GetHalfScaleY()) || (player->GetPosY() - player->GetHalfScaleY() > fallObj->GetPosY() + fallObj->GetHalfScaleY())))
    {
        // �������Ă��Ȃ�
    }
    else
    {
        fallObj->OnHit(true);
        printfDx("��������");
    }
}
