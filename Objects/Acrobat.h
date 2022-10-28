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
    void Update(float deltaTime) override;
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
    void OnHit(bool flag);

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
};
