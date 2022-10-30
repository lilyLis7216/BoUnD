#include "Title.h"
#include "DxLib.h"
#include "../Manager/SceneManager.h"
#include "../Manager/SoundManager.h"
#include "../Append/UserInterface.h"
#include "../Append//FrameRate.h"
#include "../Append/Controller.h"

Title::Title()
    : deltaTime(0)
    , alpha(100)
    , alphaCoolTime(0.5f)
{
    // フレームレート制御のインスタンス生成
    frameRate = new FrameRate();

    // 背景の読み込み
    backgroundImage = LoadGraph("Assets/Background/title.png");

    // ロゴの読み込み
    logo = LoadGraph("Assets/Background/logo.png");

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
    
    // 半透明描画モード
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, (int)alpha);

    // ゲーム画面への指示表示
    UserInterface::UIText(550, 720, GetColor(0, 0, 0), "Start to  Play!");

    // 通常描画モードに戻す
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

    // ロゴの表示
    DrawRotaGraph(960, 300, 3.0f, 0, logo, TRUE);
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
