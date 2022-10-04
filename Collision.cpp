#include "Collision.h"
#include "Player.h"
#include "FallObj.h"

Collision::Collision()
{
}

Collision::~Collision()
{
}

void Collision::Coll(Player* player, FallObj* obj)
{
    if ((player->GetPosX() < obj->GetPosX() || player->GetPosX() > obj->GetPosX()) && 
        (player->GetPosY() < obj->GetPosY() || player->GetPosY() > obj->GetPosY()))
    {

    }
}
