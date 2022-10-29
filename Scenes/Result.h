#pragma once
#include "../BaseClass/BaseScene.h"

class FrameRate;

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

    /** 白色*/
    int whiteCr;

    /** 黄色*/
    int yellowCr;

    /** 赤色ピエロ*/
    int clownRed;

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

    /** 1回目かどうか*/
    bool isFirstPlay;
};