#include "Game.h"
#include "DxLib.h"
#include "FrameRate.h"
#include "SceneManager.h"
#include "Background.h"
#include "Acrobat.h"
#include "Collision.h"
#include "GameManager.h"

Player* Game::player = nullptr;

//--------------------------------------------------------------------------------------------------------------------------------
// @brief コンストラクタ
//--------------------------------------------------------------------------------------------------------------------------------
Game::Game()
    :deltaTime(0)
{
    player = new Player();
    frameRate = new FrameRate();
    bg = new Background();
    fo = nullptr;
    coll = new Collision();
    GameManager::ResetAll();
}

//--------------------------------------------------------------------------------------------------------------------------------
// @brief デストラクタ
//--------------------------------------------------------------------------------------------------------------------------------
Game::~Game()
{
    delete player;
    delete frameRate;
    delete bg;
    delete coll;
}

//--------------------------------------------------------------------------------------------------------------------------------
// @brief ゲーム更新処理
//--------------------------------------------------------------------------------------------------------------------------------
void Game::Update()
{
    frameRate->Update();
    deltaTime = frameRate->GetDeltaTime();

    GameManager::Update(deltaTime);

    player->Update(deltaTime);

    if (fo == nullptr)
    {
        fo = new Acrobat();
    }
    if (fo != nullptr)
    {
        coll->Coll(player, fo);
    }
    fo->Update(deltaTime);
    if (fo->GetPosX() > 1500 || fo->GetPosY() > 1080)
    {
        delete fo;
        fo = nullptr;
        //player->Miss();
    }
    // Mキーが押されたら 
    if (CheckHitKey(KEY_INPUT_M))
    {
        // シーンをメニューに変更
        SceneManager::ChangeScene(SceneManager::SceneState::Scene_Menu);
    }
    if (player->GetLife() < 0)
    {
        SceneManager::ChangeScene(SceneManager::SceneState::Scene_Result);
    }
}

//--------------------------------------------------------------------------------------------------------------------------------
// @brief ゲーム描画処理
//--------------------------------------------------------------------------------------------------------------------------------
void Game::Draw()
{
    bg->Draw();
    DrawString(0, 0, "ゲーム画面です。", GetColor(255, 255, 255));
    DrawString(0, 20, "Mキーを押すとメニュー画面に戻ります。", GetColor(255, 255, 255));
    DrawFormatString(200, 0, GetColor(255, 255, 255), "FPS:%5.4f", deltaTime);
    DrawFormatString(0, 40, GetColor(255, 255, 255), "%f", GameManager::GetTimer());

    if (fo != nullptr)fo->Draw();

    player->Draw();
}
