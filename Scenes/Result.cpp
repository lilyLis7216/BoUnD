#include "Result.h"
#include "DxLib.h"
#include "../Manager/SceneManager.h"
#include "../Manager/SoundManager.h"
#include "../Manager/GameManager.h"

Result::Result()
{
}

Result::~Result()
{
}

void Result::Update()
{
    SoundManager::StartSound(2);
    if (CheckHitKey(KEY_INPUT_M))
    {
        SoundManager::StopAll();
        SceneManager::ChangeScene(SceneManager::SceneState::Scene_Title);
    }
}

void Result::Draw()
{
    int fontSize = 60;
    int white = GetColor(255, 255, 255);
    DrawString(600, fontSize * 7, "リザルト画面です。", white);
    DrawString(600, fontSize * 8, "Mキーを押すとメニュー画面に戻ります。", white);
    DrawFormatString(600, fontSize * 9, white, "Score:%d", GameManager::GetScore());
    DrawFormatString(600, fontSize * 10, white, "MaxComb:%d", GameManager::GetMaxComb());
}
