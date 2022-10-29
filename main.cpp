#include <windows.h>
#include "DxLib.h"
#include "Manager/SceneManager.h"
#include "Manager/GameManager.h"
#include "Manager/SoundManager.h"
#include "Append/UserInterface.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    // DxLib������
    ChangeWindowMode(TRUE);
    SetGraphMode(1920, 1080, 32);
    if (DxLib_Init() == -1)return -1;

    // �V�[���}�l�[�W���[�̃C���X�^���X����
    SceneManager::CreateInstance();

    // �Q�[���}�l�[�W���[�̃C���X�^���X����
    GameManager::CreateInstance();

    // �T�E���h�}�l�[�W���[�̃C���X�^���X����
    SoundManager::CreateInstance();

    // ���[�U�C���^�[�t�F�[�X�̃C���X�^���X����
    UserInterface* ui = new UserInterface();

    // �Q�[�����[�v
    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        // �V�[���̍X�V
        SceneManager::Update();

        //��ʍX�V����
        ClearDrawScreen();

        // �V�[���̕`��
        SceneManager::Draw();

        ScreenFlip();
    }

    // �V�[���}�l�[�W���[�̃C���X�^���X�폜
    SceneManager::DeleteInstance();

    // �Q�[���}�l�[�W���[�̃C���X�^���X�폜
    GameManager::DeleteInstance();

    // �T�E���h�}�l�[�W���[�̃C���X�^���X�폜
    SoundManager::DeleteInstance();

    // ���[�U�C���^�[�t�F�[�X�̃C���X�^���X�폜
    delete ui;

    DxLib_End();
    return 0;
}
