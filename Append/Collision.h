#pragma once

class BaseObject;
class Player;
class Acrobat;

class Collision
{
public:
    /**
    * Collision�̃R���X�g���N�^
    */
    Collision();

    /**
    * Collision�̃f�X�g���N�^
    */
    ~Collision();

    static void Coll(Player* player, Acrobat* acrobat);
private:
};
