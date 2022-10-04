#pragma once

class Player;
class FallObj;

class Collision
{
public:
    Collision();
    ~Collision();

    void Coll(Player* player, FallObj* obj);

private:
};