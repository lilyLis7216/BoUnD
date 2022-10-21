#include "Result.h"
#include "DxLib.h"
#include "SceneManager.h"
#include "SoundManager.h"
#include "GameManager.h"

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
        SceneManager::ChangeScene(SceneManager::SceneState::Scene_Menu);
    }
}

void Result::Draw()
{
    int fontSize = 60;
    int white = GetColor(255, 255, 255);
    DrawString(600, fontSize * 7, "���U���g��ʂł��B", white);
    DrawString(600, fontSize * 8, "M�L�[�������ƃ��j���[��ʂɖ߂�܂��B", white);
    DrawFormatString(600, fontSize * 9, white, "Score:%d", GameManager::GetScore());
    DrawFormatString(600, fontSize * 10, white, "MaxComb:%d", GameManager::GetMaxComb());
}
