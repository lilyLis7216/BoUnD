#include "Game.h"
#include "DxLib.h"
#include "SceneManager.h"
#include "GameManager.h"
#include "SoundManager.h"
#include "AcrobatManager.h"
#include "Background.h"
#include "FrameRate.h"
#include "Player.h"
#include "Acrobat.h"
#include "Collision.h"

//--------------------------------------------------------------------------------------------------------------------------------
// @brief コンストラクタ
//--------------------------------------------------------------------------------------------------------------------------------
Game::Game()
    :deltaTime(0)
{
    GameManager::ResetAll();
    bg = new Background();
    frameRate = new FrameRate();
    player = new Player();
    coll = new Collision();
    AcrobatManager::CreateInstance();
}

//--------------------------------------------------------------------------------------------------------------------------------
// @brief デストラクタ
//--------------------------------------------------------------------------------------------------------------------------------
Game::~Game()
{
    delete bg;
    delete frameRate;
    delete player;
    delete coll;
    AcrobatManager::DeleteInstance();
}

//--------------------------------------------------------------------------------------------------------------------------------
// @brief ゲーム更新処理
//--------------------------------------------------------------------------------------------------------------------------------
void Game::Update()
{
    SoundManager::StartSound(1);

    frameRate->Update();
    deltaTime = frameRate->GetDeltaTime();

    GameManager::Update(deltaTime);

    player->Update(deltaTime);

    AcrobatManager::Update(deltaTime, player);

    // Mキーが押されたら 
    if (CheckHitKey(KEY_INPUT_M))
    {
        SoundManager::StopAll();
        // シーンをメニューに変更
        SceneManager::ChangeScene(SceneManager::SceneState::Scene_Menu);
    }
    if (player->GetLife() < 0 || GameManager::GetTimer() < 0)
    {
        SoundManager::StopAll();
        SceneManager::ChangeScene(SceneManager::SceneState::Scene_Result);
    }
}

//--------------------------------------------------------------------------------------------------------------------------------
// @brief ゲーム描画処理
//--------------------------------------------------------------------------------------------------------------------------------
void Game::Draw()
{
    int white = GetColor(255, 255, 255);
    bg->Draw();
    DrawString(0, 0, "ゲーム画面です。", white);
    DrawString(0, 20, "Mキーを押すとメニュー画面に戻ります。", white);

    DrawFormatString(1536, 36, white, "Score:%d", GameManager::GetScore());
    DrawFormatString(1536, 72, white, "Comb:%d", GameManager::GetComb());
    DrawFormatString(1536, 108, white, "Time:%d", (int)GameManager::GetTimer());
    DrawFormatString(1536, 144, white, "FPS:%5.4f", deltaTime);


    AcrobatManager::Draw();

    player->Draw();
}
