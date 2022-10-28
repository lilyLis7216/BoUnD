#include "Game.h"
#include "DxLib.h"
#include "../Manager/SceneManager.h"
#include "../Manager/GameManager.h"
#include "../Manager/SoundManager.h"
#include "../Manager/AcrobatManager.h"
#include "../Objects/Player.h"
#include "../Objects/Acrobat.h"
#include "../Append/FrameRate.h"
#include "../Append/Collision.h"
#include "../Append/UserInterface.h"

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

Game::~Game()
{
    delete frameRate;
    delete player;
    delete coll;
    AcrobatManager::DeleteInstance();
}

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

void Game::Draw()
{
    DrawGraph(0, 0, backgroundImage, TRUE);
    AcrobatManager::Draw();
    player->Draw();
    UI();
}

void Game::UI()
{
    int white = GetColor(255, 255, 255);

    // 残りタイム表示
    UserInterface::UIBox(20, 320, 20, 120, 10);
    UserInterface::UIText(40, 40, white, "Time:%d", (int)GameManager::GetTimer());

    // コンボ表示
    UserInterface::UIBox(340, 660, 20, 120, 10);
    UserInterface::UIText(360, 40, white, "Comb:%d", GameManager::GetComb());

    // 最大コンボ表示
    UserInterface::UIBox(680, 1120, 20, 120, 10);
    UserInterface::UIText(700, 40, white, "MaxComb:%d", GameManager::GetMaxComb());

    // スコア表示
    UserInterface::UIBox(1140, 1580, 20, 120, 10);
    UserInterface::UIText(1160, 40, white, "Score:%d", GameManager::GetScore());

    // 残り自機数表示
    UserInterface::UIBox(1600, 1900, 20, 120, 10);
    UserInterface::UIText(1620, 40, white, "Life:%d", player->GetLife());

    // 確認用
    //DrawFormatString(36, 180, white, "FPS:%5.4f", deltaTime);
}
