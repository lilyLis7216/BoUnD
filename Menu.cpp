#include "Menu.h"
#include "SceneManager.h"
#include "DxLib.h"

//--------------------------------------------------------------------------------------------------------------------------------
// @brief 初期化
//--------------------------------------------------------------------------------------------------------------------------------
void Menu::Initialize()
{
}

//--------------------------------------------------------------------------------------------------------------------------------
// @brief メニュー更新処理
//--------------------------------------------------------------------------------------------------------------------------------
void Menu::Update()
{
    // Gキーが押されたら
    if (CheckHitKey(KEY_INPUT_G))
    {
        // シーンをゲーム画面に変更
        SceneManager::ChangeScene(SceneManager::Scene_Game);
    }

    // Cキーが押されたら
    if (CheckHitKey(KEY_INPUT_C))
    {
        // シーンを設定画面に変更
        SceneManager::ChangeScene(SceneManager::Scene_Config);
    }
}

//--------------------------------------------------------------------------------------------------------------------------------
// @brief メニュー描画処理
//--------------------------------------------------------------------------------------------------------------------------------
void Menu::Draw()
{
    DrawString(0, 0, "メニュー画面です。", GetColor(255, 255, 255));
    DrawString(0, 20, "Gキーを押すとゲーム画面に進みます。", GetColor(255, 255, 255));
    DrawString(0, 40, "Cキーを押すと 設定 画面に進みます。", GetColor(255, 255, 255));
}

//--------------------------------------------------------------------------------------------------------------------------------
// @bried 後始末
//--------------------------------------------------------------------------------------------------------------------------------
void Menu::Finalize()
{
}
