#pragma once

class BaseObject;
class Player;
class Acrobat;

class Collision
{
public:
    Collision();
    ~Collision();

    static void Coll(Player* player, Acrobat* acrobat);
private:
};
