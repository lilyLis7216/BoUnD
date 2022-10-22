#include "Menu.h"
#include "DxLib.h"
#include "SceneManager.h"
#include "SoundManager.h"
#include "UserInterface.h"

//--------------------------------------------------------------------------------------------------------------------------------
// @brief �R���X�g���N�^
//--------------------------------------------------------------------------------------------------------------------------------
Menu::Menu()
{
    backgroundImage = LoadGraph("Assets/Background/sky.png");
    logo = LoadGraph("Assets/Background/logo.png");
    enterImage = LoadGraph("Assets/UI/enter1.png");
}

//--------------------------------------------------------------------------------------------------------------------------------
// @bried �f�X�g���N�^
//--------------------------------------------------------------------------------------------------------------------------------
Menu::~Menu()
{
}

//--------------------------------------------------------------------------------------------------------------------------------
// @brief ���j���[�X�V����
//--------------------------------------------------------------------------------------------------------------------------------
void Menu::Update()
{
    SoundManager::StartSound(0);

    // Enter�������ꂽ��
    if (CheckHitKey(KEY_INPUT_RETURN))
    {
        SoundManager::StopAll();
        // �V�[�����Q�[����ʂɕύX
        SceneManager::ChangeScene(SceneManager::SceneState::Scene_Game);
    }

    // C�L�[�������ꂽ��
    if (CheckHitKey(KEY_INPUT_C))
    {
        // �V�[����ݒ��ʂɕύX
        SceneManager::ChangeScene(SceneManager::SceneState::Scene_Config);
    }
}

//--------------------------------------------------------------------------------------------------------------------------------
// @brief ���j���[�`�揈��
//--------------------------------------------------------------------------------------------------------------------------------
void Menu::Draw()
{
    int fontSize = 60;
    DrawGraph(0, 0, backgroundImage, TRUE);
    UserInterface::UIText(600, fontSize * 10, GetColor(255, 255, 255), "���j���[��ʂł��B", fontSize);
    UserInterface::UIText(600, fontSize * 12, GetColor(255, 255, 255), "�Q�[���X�^�[�g", fontSize);
    DrawRotaGraph(400, fontSize * 12, 1.0f, 0, enterImage, TRUE);
    DrawRotaGraph(960, 300, 3.0f, 0, logo, TRUE);
}
