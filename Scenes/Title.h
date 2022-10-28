#pragma once
#include "../BaseClass/BaseScene.h"

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
    /** ロゴ*/
    int logo;

    /** エンターキー画像*/
    int enterImage;
};
