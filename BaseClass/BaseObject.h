#pragma once

class BaseObject
{
public:
    /**
    * BaseObjectのコンストラクタ
    */
    BaseObject();

    /**
    * BaseObjectのデストラクタ
    */
    virtual ~BaseObject();

    /**
    * BaseObject更新処理の仮想関数
    * 
    * @param deltaTime 1フレームの経過時間
    */
    virtual void Update(float deltaTime) {};

    /**
    * BaseObject描画処理の仮想関数
    */
    virtual void Draw() {};

    /**
    * x座標の取得
    * 
    * @return float 現在のx座標
    */
    virtual float GetPosX() const { return posX; }

    /**
    * y座標の取得
    * 
    * @return float 現在のy座標
    */
    virtual float GetPosY() const { return posY; }

    /**
    * 横幅の取得
    * 
    * @return float 横幅
    */
    virtual float GetScaleX() const { return scaleX; }

    /**
    * 縦幅の取得
    * 
    * @return float 縦幅
    */
    virtual float GetScaleY() const { return scaleY; }

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

protected:
    /** x座標*/
    float posX;

    /** y座標*/
    float posY;

    /** 横幅*/
    float scaleX;

    /** 縦幅*/
    float scaleY;

    /** 横幅の半分*/
    float halfScaleX;

    /** 縦幅の半分*/
    float halfScaleY;

    /** 拡縮*/
    float scaling;

    /** 速度*/
    float speed;

    /** 表示画像*/
    int image;
};
