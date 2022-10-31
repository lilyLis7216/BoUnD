#pragma once
#include "../BaseClass/BaseObject.h"

/**
* Player
* BaseObjectを継承している
* プレイヤークラス
*/
class Player : public BaseObject
{
public:
    /**
    * プレイヤーのコンストラクタ
    */
    Player();

    /**
    * プレイヤーのデストラクタ
    */
    ~Player();

    /**
    * プレイヤーの更新処理
    */
    void Update(float deltaTime) override;

    /**
    * プレイヤーの描画処理
    */
    void Draw() override;

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
