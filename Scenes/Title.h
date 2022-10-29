#pragma once
#include "../BaseClass/BaseScene.h"

// 前方宣言
class FrameRate;

class Title : public BaseScene
{
public:
    /**
    * Titleのコンストラクタ
    */
    Title();

    /**
    * Titleのデストラクタ
    */
    ~Title();

    /**
    * メニューの更新処理
    */
    void Update() override;

    /**
    * メニュー画面の描画処理
    */
    void Draw()   override;

private:
    /**
    * フェード処理
    */
    void Fade();

    /** フレームレート制御用*/
    FrameRate* frameRate;

    /** ロゴ*/
    int logo;

    /** デルタタイム*/
    float deltaTime;

    /** 透明度*/
    float alpha;

    /** 透明処理クールタイム*/
    float alphaCoolTime;
};
