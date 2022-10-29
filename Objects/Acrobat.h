#pragma once
#include "../BaseClass/BaseObject.h"

class Player;

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
    void Update(float deltaTime, Player* player);

    /**
    * Acrobatの描画処理
    */
    void Draw() override;

    /**
    * 横幅半分の大きさの取得
    * 
    * @return float 横幅半分の大きさ
    */
    float GetHalfScaleX() const { return halfScaleX; }

    /**
    * 縦幅半分の大きさの取得
    * 
    * @return float 縦幅半分の大きさ
    */
    float GetHalfScaleY() const { return halfScaleY; }

    /**
    * 当たった時の処理
    * 
    * @param[in] flag 当たっているかどうか
    */
    void OnHit();

private:
    /** 跳ねるかどうか*/
    bool isBound;

    /** 跳躍力*/
    float jumpPower;

    /** 横幅半分の大きさ*/
    float halfScaleX;

    /** 縦幅半分の大きさ*/
    float halfScaleY;

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
};
