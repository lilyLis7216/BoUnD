#pragma once

class BaseObject;
class Player;
class Acrobat;

class Collision
{
public:
    struct CollInfo
    {
        float x;
        float y;
        float w;
        float h;
    };

    Collision();
    ~Collision();

    static void Coll(Player* player, Acrobat* acrobat);

    static void ObjCollUpdate(float x, float y, float w, float h);
    static void ObjCollUpdate(float x, float y, float w, float h, int acrNum);

    static void Coll();
    static CollInfo* player;
    static CollInfo acrobat[3];
private:

};
