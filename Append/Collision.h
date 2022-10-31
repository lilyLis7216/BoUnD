#pragma once

// 前方宣言
class BaseObject;
class Player;
class Acrobat;
class Box;

/**
* Collision
* 当たり判定クラス
*/
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

    /**
    * プレイヤーとアクロバットの矩形対点当たり判定
    * 
    * @param[out] player プレイヤー
    * @param[out] acrobat アクロバット
    */
    static void Coll(Player* player, Acrobat* acrobat);

    /**
    * プレイヤーとアクロバットの円形当たり判定
    * 
    * @param[out] player プレイヤー
    * @param[out] acrobat アクロバット
    */
    static void CollPtoA(Player* player, Acrobat* acrobat);

    /**
    * 箱とアクロバットの円形当たり判定
    * 
    * @param[out] box 箱
    * @param[out] acrobat アクロバット
    */
    static void CollBtoA(Box* box, Acrobat* acrobat);
};
