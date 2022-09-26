#include "SceneManager.h"
#include "Menu.h"
#include "Game.h"
#include "Config.h"



//--------------------------------------------------------------------------------------------------------------------------------
// @brief �R���X�g���N�^
//--------------------------------------------------------------------------------------------------------------------------------
SceneManager::SceneManager()
{
    nowScene  = Scene_Menu;
    nextScene = Scene_None;
    InitModule(nowScene);
}

//--------------------------------------------------------------------------------------------------------------------------------
// @brief �f�X�g���N�^
//--------------------------------------------------------------------------------------------------------------------------------
SceneManager::~SceneManager()
{
    FinModule(nowScene);
}

//--------------------------------------------------------------------------------------------------------------------------------
// @brief �V�[���̍X�V����
//--------------------------------------------------------------------------------------------------------------------------------
void SceneManager::Update()
{
    // ���̃V�[�����Z�b�g����Ă�����
    if (nextScene != Scene_None)
    {
        FinModule(nowScene);     // ���݂̃V�[���̏I�����������s
        nowScene = nextScene;    // ���̃V�[�������݂̃V�[�����Z�b�g
        nextScene = Scene_None;  // ���̃V�[�������N���A
        InitModule(nowScene);    // ���݂̃V�[����������
    }

    // ���݂̃V�[���ɂ���ď����𕪊�
    switch (nowScene)
    {
    case SceneManager::Scene_Menu:

        break;
    case SceneManager::Scene_Game:
        Game::Update();
        break;
    case SceneManager::Scene_Config:
        Config::Update();
        break;
    default:
        break;
    }
}

//--------------------------------------------------------------------------------------------------------------------------------
// @brief �V�[���̕`�揈��
//--------------------------------------------------------------------------------------------------------------------------------
void SceneManager::Draw()
{
    // ���݂̃V�[���ɂ���ď����𕪊�
    switch (nowScene)
    {
    case SceneManager::Scene_Menu:

        break;
    case SceneManager::Scene_Game:
        Game::Draw();
        break;
    case SceneManager::Scene_Config:
        Config::Draw();
        break;
    default:
        break;
    }
}

//--------------------------------------------------------------------------------------------------------------------------------
// @brief �J�ڏ���
// @param[nextScene] ���̃V�[��
//--------------------------------------------------------------------------------------------------------------------------------
void SceneManager::ChangeScene(SceneState NextScene)
{
    // ���̃V�[�����Z�b�g����
    nextScene = NextScene;
}

//--------------------------------------------------------------------------------------------------------------------------------
// @brief ���W���[���̏�����
//--------------------------------------------------------------------------------------------------------------------------------
void SceneManager::InitModule(SceneState scene)
{
    // �V�[���ɂ���ď����𕪊�
    switch (scene)
    {
    case SceneManager::Scene_Menu:

        break;
    case SceneManager::Scene_Game:
        Game::Initialize();
        break;
    case SceneManager::Scene_Config:
        Config::Initialize();
        break;
    default:
        break;
    }
}

//--------------------------------------------------------------------------------------------------------------------------------
// @brief ���W���[���̌�n��
//--------------------------------------------------------------------------------------------------------------------------------
void SceneManager::FinModule(SceneState scene)
{
    switch (scene)
    {
    case SceneManager::Scene_Menu:

        break;
    case SceneManager::Scene_Game:
        Game::Finalize();
        break;
    case SceneManager::Scene_Config:
        Config::Finalize();
        break;
    default:
        break;
    }
}
