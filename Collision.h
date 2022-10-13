#pragma once

class BaseObject;
class Player;
class Acrobat;

class Collision
{
public:
    Collision();
    ~Collision();

    void Coll(Player* player, Acrobat* acrobat);

    static void Test(Player* player, Acrobat* acrobat);
private:
};
