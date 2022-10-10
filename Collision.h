#pragma once

class Player;
class Acrobat;

class Collision
{
public:
    Collision();
    ~Collision();

    void Coll(Player* player, Acrobat* acrobat);
private:
};
