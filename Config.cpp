#include "Config.h"
#include "SceneManager.h"
#include "DxLib.h"


void Config::Initialize()
{
}

void Config::Update()
{
    // M�L�[�������ꂽ��
    if (CheckHitKey(KEY_INPUT_M))
    {
        // �V�[�������j���[�ɕύX
        SceneManager::ChangeScene(SceneManager::SceneState::Scene_Menu);
    }
}

void Config::Draw()
{
    DrawString(0, 0, "�ݒ��ʂł��B", GetColor(255, 255, 255));
    DrawString(0, 20, "M�L�[�������ƃ��j���[��ʂɖ߂�܂��B", GetColor(255, 255, 255));
}

void Config::Finalize()
{
}
