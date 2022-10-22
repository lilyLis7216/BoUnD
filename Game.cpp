#include "Game.h"
#include "DxLib.h"
#include "SceneManager.h"
#include "GameManager.h"
#include "SoundManager.h"
#include "AcrobatManager.h"
#include "FrameRate.h"
#include "Player.h"
#include "Acrobat.h"
#include "Collision.h"
#include "UserInterface.h"

//--------------------------------------------------------------------------------------------------------------------------------
// @brief コンストラクタ
//--------------------------------------------------------------------------------------------------------------------------------
Game::Game()
    :deltaTime(0)
{
    GameManager::ResetAll();
    frameRate = new FrameRate();
    player = new Player();
    coll = new Collision();
    AcrobatManager::CreateInstance();
    backgroundImage = LoadGraph("Assets/Background/test.png");
}

//--------------------------------------------------------------------------------------------------------------------------------
// @brief デストラクタ
//--------------------------------------------------------------------------------------------------------------------------------
Game::~Game()
{
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
    DrawGraph(0, 0, backgroundImage, TRUE);
    AcrobatManager::Draw();
    player->Draw();
    UI();
}

void Game::UI()
{
    int fontSize = 60;
    int white = GetColor(255, 255, 255);
    UserInterface::UIText(1518, 60, white, "Score:%d", GameManager::GetScore(), fontSize);
    UserInterface::UIText(1518, 120, white, "Comb:%d", GameManager::GetComb(), fontSize);
    UserInterface::UIText(1518, 180, white, "MaxComb:%d", GameManager::GetMaxComb(), fontSize);
    UserInterface::UIText(36, 60, white, "Time:%d", (int)GameManager::GetTimer(), fontSize);
    UserInterface::UIText(36, 120, white, "Life:%d", player->GetLife(), fontSize);
    DrawFormatString(36, fontSize * 3, white, "FPS:%5.4f", deltaTime);
}
