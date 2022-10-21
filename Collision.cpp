#include "Collision.h"
#include "Player.h"
#include "Acrobat.h"
#include "DxLib.h"
#include <math.h>
#include "SoundManager.h"
#include "GameManager.h"

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
    //if (player->GetPosX() - player->GetHalfScaleX() < acrobat->GetPosX() &&
    //    player->GetPosX() + player->GetHalfScaleX() > acrobat->GetPosX() &&
    //    player->GetPosY() - player->GetHalfScaleY() <= acrobat->GetPosY() + acrobat->GetHalfScaleY())
    //{
    //    acrobat->SetBound(true);
    //    SoundManager::StartSound(5);
    //    GameManager::AddScore(100);
    //    GameManager::AddComb();
    //    //printfDx("“–‚½‚Á‚½");
    //}

    /*if ((pRight > acrobat->GetPosX()) &&
        (pLeft < acrobat->GetPosX()) &&
        (pTop < acrobat->GetPosY()) &&
        (pButtom > acrobat->GetPosY()))
    {
        acrobat->SetBound(true);
        GameManager::AddScore(100);
        GameManager::AddComb();
    }*/

    if ((pLeft < acrobat->GetPosX()) && (acrobat->GetPosX() < pRight) && (player->GetPosY() < acrobat->GetPosY()))
    {
        acrobat->OnHit(true);
        SoundManager::StartSound(5);
    }
}

