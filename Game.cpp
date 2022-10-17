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
    if (player->GetLife() < 1 || GameManager::GetTimer() < 0)
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
    bg->Draw();
    //DrawString(0, 0, "ゲーム画面です。", white);
    //DrawString(0, 36, "Mキーを押すとメニュー画面に戻ります。", white);

    AcrobatManager::Draw();

    player->Draw();
    UI();
}

void Game::UI()
{
    int fontSize = 60;
    int white = GetColor(255, 255, 255);
    DrawFormatString(1536, fontSize, white, "Score:%d", GameManager::GetScore());
    DrawFormatString(1536, fontSize * 2, white, "Comb:%d", GameManager::GetComb());
    DrawFormatString(36, fontSize, white, "Time:%d", (int)GameManager::GetTimer());
    DrawFormatString(36, fontSize * 2, white, "Life:%d", player->GetLife());
    DrawFormatString(36, fontSize * 3, white, "FPS:%5.4f", deltaTime);
}
