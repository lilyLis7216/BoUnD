#pragma once
#include "BaseScene.h"

// 前方宣言
class FrameRate;
class Player;
class Collision;

class Game : public BaseScene
{
public:
    /**
    * Gameのコンストラクタ
    */
    Game();

    /**
    * Gameのデストラクタ
    */
    ~Game();

    /**
    * ゲーム画面の更新処理
    */
    void Update() override;

    /**
    * ゲーム画面の描画処理
    */
    void Draw()   override;

    /**
    * Ui処理
    */
    void UI();

private:
    /** フレームレート制御用*/
    FrameRate* frameRate;

    /** プレイヤー*/
    Player* player;

    /** 当たり判定*/
    Collision* coll;

    /** デルタタイム*/
    float deltaTime;
};
