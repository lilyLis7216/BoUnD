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

void Collision::Coll(Player* player, Acrobat* acrobat)
{
    if (player->GetPosX() - player->GetHalfScaleX() < acrobat->GetPosX() && 
        player->GetPosX() + player->GetHalfScaleX() > acrobat->GetPosX() && 
        player->GetPosY() - player->GetHalfScaleY() <= acrobat->GetPosY() + acrobat->GetHalfScaleY())
    {
        acrobat->SetBound(true);
        printfDx("��������");
    }
}
