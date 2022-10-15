#include "Result.h"
#include "DxLib.h"
#include "SceneManager.h"
#include "SoundManager.h"

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
    DrawString(0, 0, "���U���g��ʂł��B", GetColor(255, 255, 255));
    DrawString(0, 20, "M�L�[�������ƃ��j���[��ʂɖ߂�܂��B", GetColor(255, 255, 255));
}
