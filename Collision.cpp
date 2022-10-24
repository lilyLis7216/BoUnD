#include "Collision.h"
#include "Player.h"
#include "Acrobat.h"
#include "DxLib.h"
#include <math.h>
#include "SoundManager.h"
#include "GameManager.h"

Collision::CollInfo* Collision::player = NULL;
Collision::CollInfo Collision::acrobat[3] = { NULL };


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

//void Collision::ObjCollUpdate(float x, float y, float w, float h)
//{
//    player->x = x;
//    player->y = y;
//    player->w = w;
//    player->h = h;
//}
//
//void Collision::ObjCollUpdate(float x, float y, float w, float h, int acrNum)
//{
//    acrobat[acrNum].x = x;
//    acrobat[acrNum].y = y;
//    acrobat[acrNum].w = w;
//    acrobat[acrNum].h = h;
//}
//
//void Collision::Coll()
//{
//    float pLeft = player->x - player->w;
//    float pRight = player->x + player->w;
//    float pTop = player->y - player->h;
//    float pButtom = player->y + player->h;
//    if ((pLeft < acrobat->x) && (acrobat->x < pRight) && (player->y < acrobat->y))
//    {
//        acrobat->OnHit(true);
//        SoundManager::StartSound(5);
//    }
//}
