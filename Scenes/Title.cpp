#include "Title.h"
#include "DxLib.h"
#include "../Manager/SceneManager.h"
#include "../Manager/SoundManager.h"
#include "../Append/UserInterface.h"

Title::Title()
{
    backgroundImage = LoadGraph("Assets/Background/title.png");
    logo = LoadGraph("Assets/Background/logo.png");
    enterImage = LoadGraph("Assets/UI/enter1.png");
}

Title::~Title()
{
}

void Title::Update()
{
    SoundManager::StartSound(0);

    // Enterが押されたら
    if (CheckHitKey(KEY_INPUT_RETURN))
    {
        SoundManager::StopAll();
        // シーンをゲーム画面に変更
        SceneManager::ChangeScene(SceneManager::SceneState::Scene_Game);
    }
}

void Title::Draw()
{
    int fontSize = 60;
    DrawGraph(0, 0, backgroundImage, TRUE);
    UserInterface::UIText(600, fontSize * 10, GetColor(255, 255, 255), "メニュー画面です。");
    UserInterface::UIText(600, fontSize * 12, GetColor(255, 255, 255), "ゲームスタート");
    DrawRotaGraph(400, fontSize * 12, 1.0f, 0, enterImage, TRUE);
    DrawRotaGraph(960, 300, 3.0f, 0, logo, TRUE);
}
