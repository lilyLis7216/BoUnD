#include "Title.h"
#include "DxLib.h"
#include "../Manager/SceneManager.h"
#include "../Manager/SoundManager.h"
#include "../Append/UserInterface.h"
#include "../Append//FrameRate.h"
#include "../Append/Controller.h"

Title::Title()
    : animCount(0)
    , animCoolTime(0)
    , animFrame(0)
    ,deltaTime(0)
    , alpha(100)
    , alphaCoolTime(0.5f)
{
    // フレームレート制御のインスタンス生成
    frameRate = new FrameRate();

    // 背景の読み込み
    backgroundImage = LoadGraph("Assets/Background/titleBG.png");

    // ロゴの読み込み
    logo = LoadGraph("Assets/Background/logo.png");

    // 紫色ピエロのアニメーション読み込み
    LoadDivGraph("Assets/Acrobat/clownPurpleIdleAnim.png", 2, 2, 1, 120, 188, purpleIdle);

    // 水色ピエロのアニメーション読み込み
    LoadDivGraph("Assets/Acrobat/clownSkyIdleAnim.png", 2, 2, 1, 120, 188, skyIdle);

    // 紫色ピエロの初期画像
    clownPurple = purpleIdle[0];

    // 水色ピエロの初期画像
    clownSky = skyIdle[0];
}

Title::~Title()
{
    // フレームレート制御のインスタンス削除
    delete frameRate;

    // 背景の後始末
    DeleteGraph(backgroundImage);

    // ロゴの後始末
    DeleteGraph(logo);
}

void Title::Update()
{
    // フレームレート制御クラスの更新
    frameRate->Update();

    // デルタタイムの取得
    deltaTime = frameRate->GetDeltaTime();

    // タイトルBGMの再生
    SoundManager::StartSound(0);

    // キャラのアニメーション
    CharaAnim();

    // 半透明処理
    Fade();

    // Enterが押されたら
    if (CheckHitKey(KEY_INPUT_RETURN) || Controller::StartInput())
    {
        // 全てのサウンドを止めて
        SoundManager::StopAll();

        // シーンをゲーム画面に変更
        SceneManager::ChangeScene(SceneManager::SceneState::Scene_Game);
    }
}

void Title::Draw()
{
    // フォントサイズの指定
    SetFontSize(100);

    // 背景の表示
    DrawGraph(0, 0, backgroundImage, TRUE);

    // 紫色ピエロ表示
    DrawRotaGraph(1600, 850, 2.0f, 0, clownPurple, TRUE);

    // 水色ピエロ表示
    DrawRotaGraph(300, 850, 2.0f, 0, clownSky, TRUE, TRUE);
    
    // 半透明描画モード
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, (int)alpha);

    // ゲーム画面への指示表示
    UserInterface::UIText(550, 720, GetColor(0, 0, 0), "Start to  Play!");

    // 通常描画モードに戻す
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

    // ロゴの表示
    DrawRotaGraph(960, 300, 3.0f, 0, logo, TRUE);
}

void Title::CharaAnim()
{
    animCoolTime -= deltaTime;

    if (animCoolTime <= 0)
    {
        animCount++;

        animCoolTime = 0.5f;
    }

    animFrame = animCount % 2;

    clownPurple = purpleIdle[animFrame];

    clownSky = skyIdle[animFrame];
}

void Title::Fade()
{
    if (alpha <= 255)
    {
        alpha += deltaTime * 100;

    }
    if (alpha >= 255)
    {
        alphaCoolTime -= deltaTime;

        if (alphaCoolTime <= 0)
        {
            alpha = 100;

            alphaCoolTime = 0.5f;
        }
    }
}
