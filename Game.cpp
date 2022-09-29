#include "Game.h"
#include "SceneManager.h"
#include "DxLib.h"

Player* Game::p = nullptr;

//--------------------------------------------------------------------------------------------------------------------------------
// @bried 初期化
//--------------------------------------------------------------------------------------------------------------------------------


Game::Game()
{
    p = new Player();
}

Game::~Game()
{
    delete p;
}

//--------------------------------------------------------------------------------------------------------------------------------
// @brief ゲーム更新処理
//--------------------------------------------------------------------------------------------------------------------------------
void Game::Update()
{
    p->Update();
    // Mキーが押されたら 
    if (CheckHitKey(KEY_INPUT_M))
    {
        // シーンをメニューに変更
        SceneManager::ChangeScene(SceneManager::SceneState::Scene_Menu);
    }
}

//--------------------------------------------------------------------------------------------------------------------------------
// @brief ゲーム描画処理
//--------------------------------------------------------------------------------------------------------------------------------
void Game::Draw()
{
    DrawString(0, 0, "ゲーム画面です。", GetColor(255, 255, 255));
    DrawString(0, 20, "Mキーを押すとメニュー画面に戻ります。", GetColor(255, 255, 255));
    p->Draw();
}

//--------------------------------------------------------------------------------------------------------------------------------
// @brief 後始末
//--------------------------------------------------------------------------------------------------------------------------------
