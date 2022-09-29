#include "Config.h"
#include "SceneManager.h"
#include "DxLib.h"


void Config::Initialize()
{
}

void Config::Update()
{
    // Mキーが押されたら
    if (CheckHitKey(KEY_INPUT_M))
    {
        // シーンをメニューに変更
        SceneManager::ChangeScene(SceneManager::SceneState::Scene_Menu);
    }
}

void Config::Draw()
{
    DrawString(0, 0, "設定画面です。", GetColor(255, 255, 255));
    DrawString(0, 20, "Mキーを押すとメニュー画面に戻ります。", GetColor(255, 255, 255));
}

void Config::Finalize()
{
}
