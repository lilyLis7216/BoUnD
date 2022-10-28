#pragma once
#include "../BaseClass/BaseScene.h"

class Result : public BaseScene
{
public:
    /**
    * Resultのコンストラクタ
    */
    Result();

    /**
    * Resultのデストラクタ
    */
    ~Result();

    /**
    * リザルト画面の更新処理
    */
    void Update() override;

    /**
    * リザルト画面の描画処理
    */
    void Draw() override;
};