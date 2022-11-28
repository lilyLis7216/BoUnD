#include "Game.h"
#include "DxLib.h"
#include "../Manager/SceneManager.h"
#include "../Manager/GameManager.h"
#include "../Manager/SoundManager.h"
#include "../Manager/AcrobatManager.h"
#include "../Objects/Player.h"
#include "../Objects/Acrobat.h"
#include "../Objects//Box.h"
#include "../Append/FrameRate.h"
#include "../Append/Collision.h"
#include "../Append/UserInterface.h"

Game::Game()
    :deltaTime(0)
{
    // ゲームのリセット
    GameManager::ResetAll();

    // フレームレート制御のインスタンス生成
    frameRate = new FrameRate();

    // プレイヤーのインスタンス生成
    player = new Player();

    // 箱のインスタンス生成
    box = new Box();

    // コリジョンのインスタンス生成
    coll = new Collision();

    // アクロバットマネージャーのインスタンス生成
    AcrobatManager::CreateInstance();

    // 背景の読み込み
    backgroundImage = LoadGraph("Assets/Background/gameBG.png");

    // 白色
    whiteCr = GetColor(255, 255, 255);

    // 黒色
    blackCr = GetColor(0, 0, 0);

    // 水色
    skyCr = GetColor(0, 255, 255);
}

Game::~Game()
{
    // フレームレート制御のインスタンス削除
    delete frameRate;

    // プレイヤーのインスタンス削除
    delete player;

    // 箱のインスタンス削除
    delete box;

    // コリジョンのインスタンス削除
    delete coll;

    // アクロバットマネージャーのインスタンス削除
    AcrobatManager::DeleteInstance();

    // 背景の後始末
    DeleteGraph(backgroundImage);
}

void Game::Update()
{
    // フレームレート制御クラスの更新
    frameRate->Update();

    // デルタタイムの取得
    deltaTime = frameRate->GetDeltaTime();

    // ゲームBGMの再生
    SoundManager::StartSound(1);

    // ゲームマネージャーの更新
    GameManager::Update(deltaTime);

    // プレイヤーの更新
    player->Update(deltaTime);

    // アクロバッターマネージャーの更新
    AcrobatManager::Update(deltaTime, player, box);

    // Mキーが押されたら 
    if (CheckHitKey(KEY_INPUT_M))
    {
        // 全てのサウンドを止めて
        SoundManager::StopAll();

        // シーンをタイトル画面に変更
        SceneManager::ChangeScene(SceneManager::SceneState::Scene_Title);
    }

    // Rキーが押されたら 
    if (CheckHitKey(KEY_INPUT_R))
    {
        // 全てのサウンドを止めて
        SoundManager::StopAll();

        // シーンをリザルト画面に変更
        SceneManager::ChangeScene(SceneManager::SceneState::Scene_Result);
    }

    // タイマーが0になったら
    if ( GameManager::GetTimer() < 0)
    {
        // 全てのサウンドを止めて
        SoundManager::StopAll();

        // シーンヲリザルト画面に変更
        SceneManager::ChangeScene(SceneManager::SceneState::Scene_Result);
    }
}

void Game::Draw()
{
    // 背景表示
    DrawGraph(0, 0, backgroundImage, TRUE);

    // 箱表示
    box->Draw();

    // プレイヤー表示
    player->Draw();

    // アクロバットマネージャー表示
    AcrobatManager::Draw();

    // UI表示
    UI();
}

void Game::UI()
{
    // フォントサイズの指定
    SetFontSize(60);

    int tmp1 = 920;
    int tmp2 = 1020;
    int tmp3 = 940;
    // 残りタイム表示
    UserInterface::UIBox(170, 470, 20, 120, 10, blackCr, skyCr);
    UserInterface::UIText(190, 40, whiteCr, "Time:%d", (int)GameManager::GetTimer());
    //UserInterface::UIBox(170, 470, tmp1, tmp2, 10, blackCr, skyCr);
    //UserInterface::UIText(190, tmp3, whiteCr, "Time:%d", (int)GameManager::GetTimer());

    // コンボ表示
    UserInterface::UIBox(490, 810, 20, 120, 10, blackCr, skyCr);
    UserInterface::UIText(510, 40, whiteCr, "Comb:%02d", GameManager::GetComb());
    //UserInterface::UIBox(490, 810, tmp1, tmp2, 10, blackCr, skyCr);
    //UserInterface::UIText(510, tmp3, whiteCr, "Comb:%02d", GameManager::GetComb());

    // 最大コンボ表示
    UserInterface::UIBox(830, 1270, 20, 120, 10, blackCr, skyCr);
    UserInterface::UIText(850, 40, whiteCr, "MaxComb:%02d", GameManager::GetMaxComb());
    //UserInterface::UIBox(830, 1270, tmp1, tmp2, 10, blackCr, skyCr);
    //UserInterface::UIText(850, tmp3, whiteCr, "MaxComb:%02d", GameManager::GetMaxComb());

    // スコア表示
    UserInterface::UIBox(1290, 1730, 20, 120, 10, blackCr, skyCr);
    UserInterface::UIText(1310, 40, whiteCr, "Score:%05d", GameManager::GetScore());
    //UserInterface::UIBox(1290, 1730, tmp1, tmp2, 10, blackCr, skyCr);
    //UserInterface::UIText(1310, tmp3, whiteCr, "Score:%05d", GameManager::GetScore());

    // fps確認用
    //DrawFormatString(36, 180, white, "FPS:%5.4f", deltaTime);
}
