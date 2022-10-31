#pragma once
#include "../BaseClass/BaseScene.h"

// 前方宣言
class FrameRate;
class Player;
class Box;
class Collision;

/**
* Gameクラス
* BaseSceneを継承している
*/
class Game : public BaseScene
{
public:
    /**
    * ゲームのコンストラクタ
    */
    Game();

    /**
    * ゲームのデストラクタ
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

    /** 箱*/
    Box* box;

    /** 当たり判定*/
    Collision* coll;

    /** デルタタイム*/
    float deltaTime;

    /** 白色*/
    int whiteCr;

    /** 黒色*/
    int blackCr;

    /** 水色*/
    int skyCr;
};
