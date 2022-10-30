#include "Result.h"
#include "DxLib.h"
#include "../Manager/SceneManager.h"
#include "../Manager/SoundManager.h"
#include "../Manager/GameManager.h"
#include "../Append/UserInterface.h"
#include "../Append/FrameRate.h"
#include "../Append/Controller.h"

Result::Result()
    : animCount(0)
    , animCoolTime(0)
    , animFrame(0)
    , deltaTime(0)
    , alpha(100)
    , alphaCoolTime(0.5f)
    , isFirstPlay(false)
{
    // フレームレート制御のインスタンス生成
    frameRate = new FrameRate();

    // 背景の読み込み
    backgroundImage = LoadGraph("Assets/Background/result.png");

    // 紫色ピエロのアニメーション読み込み
    LoadDivGraph("Assets/Acrobat/clownPurpleAnim.png", 2, 2, 1, 120, 188, purpleIdle);

    // 水色ピエロのアニメーション読み込み
    LoadDivGraph("Assets/Acrobat/clownSkyAnim.png", 2, 2, 1, 120, 188, skyIdle);

    // 赤色ピエロの読み込み
    clownRed = LoadGraph("Assets/Acrobat/p3_16.png");

    // 紫色ピエロの初期画像
    clownPurple = purpleIdle[0];

    // 水色ピエロの初期画像
    clownSky = purpleIdle[0];

    // 白色
    whiteCr = GetColor(255, 255, 255);

    // 黄色
    yellowCr = GetColor(255, 255, 0);
}

Result::~Result()
{
    // フレームレート制御のインスタンス削除
    delete frameRate;

    // 背景の後始末
    DeleteGraph(backgroundImage);
}

void Result::Update()
{
    // フレームレート制御クラスの更新
    frameRate->Update();

    // デルタタイムの取得
    deltaTime = frameRate->GetDeltaTime();

    // 1回も再生していなければ
    if (!isFirstPlay)
    {
        // リザルトBGMの再生
        SoundManager::StartSound(2);
        isFirstPlay = true;
    }

    // キャラのアニメーション
    CharaAnim();
 
    // 半透明処理
    Fade();

    // MキーまたはコントローラーのXボタンが押されていたら
    if (CheckHitKey(KEY_INPUT_M) || Controller::XInput())
    {
        // 全てのサウンドを止めて
        SoundManager::StopAll();

        // シーンをタイトル画面に変更する
        SceneManager::ChangeScene(SceneManager::SceneState::Scene_Title);
    }
}

void Result::Draw()
{
    // フォントサイズの指定
    SetFontSize(100);

    // 背景の表示
    DrawGraph(0, 0, backgroundImage, TRUE);

    // リザルト画面であることの表示
    UserInterface::UIText(400, 160, whiteCr, "  ------Result------  ");

    // リザルト表示用枠
    UserInterface::UIBox(400, 1500, 300, 700, 20, GetColor(0, 0, 0), GetColor(0, 255, 255));

    // 最終スコアの表示
    UserInterface::UIText(500, 350, yellowCr, "Score     %05d", GameManager::GetScore());
    DrawLine(500, 450, 1350, 450, whiteCr, 10);

    // 最大コンボ数の表示
    UserInterface::UIText(500, 500, yellowCr, "MaxComb     %02d", GameManager::GetMaxComb());
    DrawLine(500, 600, 1350, 600, whiteCr, 10);

    // 赤色ピエロ表示
    DrawRotaGraph(1570, 460, 1.0f, 0, clownRed, TRUE, TRUE, TRUE);

    // 紫色ピエロ表示
    DrawRotaGraph(1600, 850, 2.0f, 0, clownPurple, TRUE);

    // 水色ピエロ表示
    DrawRotaGraph(300, 850, 2.0f, 0, clownSky, TRUE, TRUE);

    // 半透明描画モード
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, (int)alpha);

    // タイトル画面への指示表示
    UserInterface::UIText(600, 850, GetColor(0, 0, 255), "X");
    UserInterface::UIText(700, 850, whiteCr, " to Title");

    // 通常描画モードに戻す
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void Result::CharaAnim()
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

void Result::Fade()
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
