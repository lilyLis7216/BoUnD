#pragma once
#include "../BaseClass/BaseObject.h"

// 前方宣言
class Player;
class Box;

/**
* Acrobatクラス
* BaseObjectを継承している
*/
class Acrobat : public BaseObject
{
public:
    /**
    * アクロバットのコンストラクタ
    */
    Acrobat();

    /**
    * アクロバットのデストラクタ
    */
    ~Acrobat();

    /**
    * アクロバットの更新処理
    */
    void Update(float deltaTime, Player* player, Box* box);

    /**
    * アクロバットの描画処理
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

    /**
    * 死んでいるかどうかの取得
    * 
    * @return isDead
    */
    bool GetIsDead()const { return isDead; }

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
    
    /** 移動できるかどうか*/
    bool isMove;

    /** 死んでいるかどうか*/
    bool isDead;

    /** 消滅時間*/
    float vanishTime;

    /** 消滅時間初期化数値*/
    const float initVanishTime = 3.0f;
};
