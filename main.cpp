#include <windows.h>
#include "DxLib.h"
#include "Manager/SceneManager.h"
#include "Manager/GameManager.h"
#include "Manager/SoundManager.h"
#include "Append/UserInterface.h"
#include "Append/Controller.h"

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
    UserInterface::CreateInstance();

    // �R���g���[���[�̃C���X�^���X����
    Controller::CreateInstance();


    // �Q�[�����[�v
    // �G���[���b�Z�W���Ȃ��AESC�L�[��������Ă��炸�ABack�{�^���̓��͂��Ȃ��ԃ��[�v����
    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0 && !Controller::BackInput())
    {
        // �V�[���̍X�V
        SceneManager::Update();

        // �R���g���[���[�̍X�V
        Controller::Update();

        //��ʍX�V����
        ClearDrawScreen();

        // �V�[���̕`��
        SceneManager::Draw();

        ScreenFlip();
    }

    // �R���g���[���[�̃C���X�^���X�폜
    Controller::DeleteInstance();

    // ���[�U�C���^�[�t�F�[�X�̃C���X�^���X�폜
    UserInterface::DeleteInstance();

    // �T�E���h�}�l�[�W���[�̃C���X�^���X�폜
    SoundManager::DeleteInstance();

    // �Q�[���}�l�[�W���[�̃C���X�^���X�폜
    GameManager::DeleteInstance();

    // �V�[���}�l�[�W���[�̃C���X�^���X�폜
    SceneManager::DeleteInstance();

    DxLib_End();
    return 0;
}
