#pragma once
#include "../BaseClass/BaseObject.h"

class Player : public BaseObject
{
public:
    /**
    * Playerのコンストラクタ
    */
    Player();

    /**
    * Playerのデストラクタ
    */
    ~Player();

    /**
    * Playerの更新処理
    */
    void Update(float deltaTime) override;

    /**
    * Playerの描画処理
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
    * 自機失敗処理
    */
    void Miss() { life--; }

    /**
    * 残機の取得
    * 
    * @return int 残機
    */
    int GetLife() const { return life; }

private:
    /**
    * 移動処理
    */
    void Move();

    /**
    * 位置調整処理
    */
    void AdjustPos();

    /**
    * アニメーション処理
    */
    void Animation();

    /** 横幅の半分*/
    float halfScaleX;

    /** 縦幅の半分*/
    float halfScaleY;

    /** 残機*/
    int life;

    /** 歩きアニメーション*/
    int walkAnim[2] = { 0 };

    /** アニメーションのカウント*/
    int animCount;

    /** アニメーションのクールタイム*/
    float animCoolTime;

    /** アニメーションのフレーム*/
    int animFrame;

    /** デルタタイム*/
    float deltaTime;

};
