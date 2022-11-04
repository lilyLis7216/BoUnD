#include "Collision.h"
#include "DxLib.h"
#include <math.h>
#include "../Objects/Player.h"
#include "../Objects/Acrobat.h"
#include "../Objects/Box.h"
#include "../Manager/SoundManager.h"
#include "../Manager/GameManager.h"
#include "../Manager/AcrobatManager.h"

Collision::Collision()
{
}

Collision::~Collision()
{
}

void Collision::Coll(Player* player, Acrobat* acrobat)
{
    float pLeft = player->GetPosX() - player->GetHalfScaleX();
    float pRight = player->GetPosX() + player->GetHalfScaleX();
    float pTop = player->GetPosY() - player->GetHalfScaleY();
    float pButtom = player->GetPosY() + player->GetHalfScaleY();

    if ((pLeft < acrobat->GetPosX()) && (acrobat->GetPosX() < pRight) && (player->GetPosY() < acrobat->GetPosY()))
    {
        acrobat->OnHit();
        SoundManager::StartSound(5);
    }
}

void Collision::CollPtoA(Player* player, Acrobat* acrobat)
{
    float pX = player->GetPosX();
    float pY = player->GetPosY();
    float pR = player->GetHalfScaleX();

    float aX = acrobat->GetPosX();
    float aY = acrobat->GetPosY();
    float aR = acrobat->GetHalfScaleX();

    float vecX = pX - aX;
    float vecY = pY - aY;
    double vec = sqrt(vecX * vecX + vecY * vecY);

    if (vec < pR + aR)
    {
        // “–‚½‚Á‚Ä‚é
        acrobat->OnHit();
    }
    else
    {
        // “–‚½‚Á‚Ä‚È‚¢
    }
}

void Collision::CollBtoA(Box* box, Acrobat* acrobat)
{
    float pX = box->GetPosX();
    float pY = box->GetPosY();
    float pR = box->GetHalfScaleX();

    float aX = acrobat->GetPosX();
    float aY = acrobat->GetPosY();
    float aR = acrobat->GetHalfScaleX();

    float vecX = pX - aX;
    float vecY = pY - aY;
    double vec = sqrt(vecX * vecX + vecY * vecY);

    if (vec < pR + aR)
    {
        // “–‚½‚Á‚Ä‚é
        acrobat->boxHit();
    }
    else
    {
        // “–‚½‚Á‚Ä‚È‚¢
    }
}
