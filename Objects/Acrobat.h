#pragma once
#include "../BaseClass/BaseObject.h"

// 前方宣言
class Player;
class Box;

class Acrobat : public BaseObject
{
public:
    /**
    * Acrobatのコンストラクタ
    */
    Acrobat();

    /**
    * Acrobatのデストラクタ
    */
    ~Acrobat();

    /**
    * Acrobatの更新処理
    */
    void Update(float deltaTime, Player* player, Box* box);

    /**
    * Acrobatの描画処理
    */
    void Draw() override;

    /**
    * 当たった時の処理
    * 
    * @param[in] flag 当たっているかどうか
    */
    void OnHit();

    /**
    * 箱に到達したときの処理
    */
    void boxHit() { inBox = true; }

    /**
    * 箱の中かどうかの取得
    * 
    * @return inBox
    */
    bool GetInBox() const { return inBox; }

private:

    /**
    * 移動処理
    */
    void Move();

    /**
    * アニメーション処理
    */
    void Animation();

    /** 跳ねるかどうか*/
    bool isBound;

    /** 跳躍力*/
    float jumpPower;

    /** 前のフレームでヒットしていたか*/
    bool prevHit;

    /** 今のフレームでヒットしたか*/
    bool nowHit;

    /** 歩きアニメーション*/
    int walkAnim[2] = { 0 };

    /** アニメーションカウント*/
    int animCount;

    /** アニメーションクールタイム*/
    float animCoolTime;

    /** アニメーションフレーム*/
    int animFrame;

    /** デルタタイム*/
    float deltaTime;

    /** 回転*/
    float rotate;

    /** 箱の中かどうか*/
    bool inBox;
};
