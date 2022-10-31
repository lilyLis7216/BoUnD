#pragma once

/**
* BaseScene
* シーンの基底クラス
*/
class BaseScene
{
public:
    /**
    * BaseSceneのコンストラクタ
    */
    BaseScene();

    /**
    * BaseSceneのデストラクタ
    */
    virtual ~BaseScene();

    /**
    * BaseScene更新処理の純仮想関数
    */
    virtual void Update() = 0;

    /**
    * BaseScene描画処理の純仮想関数
    */
    virtual void Draw() = 0;

protected:
    /** 背景画像*/
    int backgroundImage;
};