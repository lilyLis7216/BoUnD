#pragma once
#include "../BaseClass/BaseObject.h"

/**
* Boxクラス
* BaseObjectを継承している
*/
class Box : public BaseObject
{
public:

    /**
    * 箱のコンストラクタ
    */
    Box();

    /**
    * 箱のデストラクタ
    */
    ~Box();

    /**
    * 箱の更新
    */
    void Update(float deltaTime) override;

    /**
    * 箱の描画
    */
    void Draw() override;
};