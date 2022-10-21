#include "Menu.h"
#include "DxLib.h"
#include "SceneManager.h"
#include "SoundManager.h"

//--------------------------------------------------------------------------------------------------------------------------------
// @brief コンストラクタ
//--------------------------------------------------------------------------------------------------------------------------------
Menu::Menu()
{
    backgroundImage = LoadGraph("Assets/Background/sky.png");
    logo = LoadGraph("Assets/Background/logo.png");
    enterImage = LoadGraph("Assets/UI/enter1.png");
}

//--------------------------------------------------------------------------------------------------------------------------------
// @bried デストラクタ
//--------------------------------------------------------------------------------------------------------------------------------
Menu::~Menu()
{
}

//--------------------------------------------------------------------------------------------------------------------------------
// @brief メニュー更新処理
//--------------------------------------------------------------------------------------------------------------------------------
void Menu::Update()
{
    SoundManager::StartSound(0);

    // Enterが押されたら
    if (CheckHitKey(KEY_INPUT_RETURN))
    {
        SoundManager::StopAll();
        // シーンをゲーム画面に変更
        SceneManager::ChangeScene(SceneManager::SceneState::Scene_Game);
    }

    // Cキーが押されたら
    if (CheckHitKey(KEY_INPUT_C))
    {
        // シーンを設定画面に変更
        SceneManager::ChangeScene(SceneManager::SceneState::Scene_Config);
    }
}

//--------------------------------------------------------------------------------------------------------------------------------
// @brief メニュー描画処理
//--------------------------------------------------------------------------------------------------------------------------------
void Menu::Draw()
{
    int fontSize = 60;
    int white = GetColor(255, 255, 255);
    DrawGraph(0, 0, backgroundImage, TRUE);
    DrawString(600, fontSize * 10, "メニュー画面です。", white);
    DrawRotaGraph(400, fontSize * 12, 1.0f, 0, enterImage, TRUE);
    DrawString(600, fontSize * 12, "：ゲームスタート！", white);
    DrawRotaGraph(960, 300, 3.0f, 0, logo, TRUE);
}
