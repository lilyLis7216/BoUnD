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

    // 残機が無くなるか、タイマーが0になったら
    if (player->GetLife() < 1 || GameManager::GetTimer() < 0)
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

    // 残りタイム表示
    UserInterface::UIBox(20, 320, 20, 120, 10, blackCr, skyCr);
    UserInterface::UIText(40, 40, whiteCr, "Time:%d", (int)GameManager::GetTimer());

    // コンボ表示
    UserInterface::UIBox(340, 660, 20, 120, 10, blackCr, skyCr);
    UserInterface::UIText(360, 40, whiteCr, "Comb:%02d", GameManager::GetComb());

    // 最大コンボ表示
    UserInterface::UIBox(680, 1120, 20, 120, 10, blackCr, skyCr);
    UserInterface::UIText(700, 40, whiteCr, "MaxComb:%02d", GameManager::GetMaxComb());

    // スコア表示
    UserInterface::UIBox(1140, 1580, 20, 120, 10, blackCr, skyCr);
    UserInterface::UIText(1160, 40, whiteCr, "Score:%05d", GameManager::GetScore());

    // 残り自機数表示
    UserInterface::UIBox(1600, 1900, 20, 120, 10, blackCr, skyCr);
    UserInterface::UIText(1620, 40, whiteCr, "Life:%d", player->GetLife());

    // fps確認用
    //DrawFormatString(36, 180, white, "FPS:%5.4f", deltaTime);
}
