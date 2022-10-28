#pragma once
#include "../BaseClass/BaseScene.h"

class Menu : public BaseScene
{
public:
    /**
    * Menuのコンストラクタ
    */
    Menu();

    /**
    * Menuのデストラクタ
    */
    ~Menu();

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
