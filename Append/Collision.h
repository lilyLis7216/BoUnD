#pragma once

class BaseObject;
class Player;
class Acrobat;

class Collision
{
public:
    /**
    * Collisionのコンストラクタ
    */
    Collision();

    /**
    * Collisionのデストラクタ
    */
    ~Collision();

    static void Coll(Player* player, Acrobat* acrobat);
private:
};
