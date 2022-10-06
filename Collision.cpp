#include "Collision.h"
#include "Player.h"
#include "Acrobat.h"
#include "DxLib.h"
#include <math.h>

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
        // “–‚½‚Á‚Ä‚¢‚È‚¢
    }
}

void Collision::Coll(Player* player, Acrobat* fallObj)
{
    if ((player->GetPosX() < fallObj->GetPosX() && player->GetPosX() + player->GetHalfScaleX() >= fallObj->GetPosX()) && player->GetPosY() <= fallObj->GetPosY() + fallObj->GetHalfScaleY())
    {
        fallObj->OnHit(true);
        printfDx("“–‚½‚Á‚½");
    }

    /*if ((player->GetPosX() - player->GetHalfScaleX() < fallObj->GetPosX() - fallObj->GetHalfScaleX() && fallObj->GetPosX() - fallObj->GetHalfScaleX() < player->GetPosX() + player->GetHalfScaleX()) ||
        (player->GetPosX() + player->GetHalfScaleX() > fallObj->GetPosX() + fallObj->GetHalfScaleX() && fallObj->GetPosX() + fallObj->GetHalfScaleX() > player->GetPosX() - player->GetHalfScaleX()))
    {
        if (player->GetPosY() - player->GetHalfScaleY() < fallObj->GetPosY() + fallObj->GetHalfScaleY() && fallObj->GetPosY() + fallObj->GetHalfScaleY() < player->GetPosY() + player->GetHalfScaleY())
        {
            fallObj->OnHit(true);
            printfDx("“–‚½‚Á‚½");
        }
    }*/
}
