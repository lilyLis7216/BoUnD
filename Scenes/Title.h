#pragma once
#include "../BaseClass/BaseScene.h"

// 前方宣言
class FrameRate;

/**
* Titleクラス
* BaseSceneを継承している
*/
class Title : public BaseScene
{
public:
    /**
    * タイトルのコンストラクタ
    */
    Title();

    /**
    * タイトルのデストラクタ
    */
    ~Title();

    /**
    * タイトル画面の更新処理
    */
    void Update() override;

    /**
    * タイトル画面の描画処理
    */
    void Draw()   override;

private:
    /**
    * キャラアニメーション
    */
    void CharaAnim();

    /**
    * フェード処理
    */
    void Fade();

    /** フレームレート制御用*/
    FrameRate* frameRate;

    /** ロゴ*/
    int logo;

    /** 紫色ピエロ*/
    int clownPurple;

    /** 水色ピエロ*/
    int clownSky;

    /** 紫色ピエロの待機アニメーション*/
    int purpleIdle[2];

    /** 水色ピエロの待機アニメーション*/
    int skyIdle[2];

    /** アニメーションのカウント*/
    int animCount;

    /** アニメーションのクールタイム*/
    float animCoolTime;

    /** アニメーションのフレーム*/
    int animFrame;

    /** デルタタイム*/
    float deltaTime;

    /** 透明度*/
    float alpha;

    /** 透明処理クールタイム*/
    float alphaCoolTime;
};
