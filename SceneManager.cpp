#include "SceneManager.h"
#include "Menu.h"
#include "Game.h"
#include "Config.h"

SceneManager::SceneState SceneManager::nowScene = SceneManager::SceneState::Scene_Menu;
SceneManager::SceneState SceneManager::nextScene = SceneManager::SceneState::Scene_None;

//--------------------------------------------------------------------------------------------------------------------------------
// @brief �R���X�g���N�^
//--------------------------------------------------------------------------------------------------------------------------------
SceneManager::SceneManager()
{
    nowScene  = SceneState::Scene_Menu;
    nextScene = SceneState::Scene_None;
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
    if (nextScene != SceneState::Scene_None)
    {
        FinModule(nowScene);     // ���݂̃V�[���̏I�����������s
        nowScene = nextScene;    // ���̃V�[�������݂̃V�[�����Z�b�g
        nextScene = SceneState::Scene_None;  // ���̃V�[�������N���A
        InitModule(nowScene);    // ���݂̃V�[����������
    }

    // ���݂̃V�[���ɂ���ď����𕪊�
    switch (nowScene)
    {
    case SceneState::Scene_Menu:
        Menu::Update();
        break;
    case SceneState::Scene_Game:
        Game::Update();
        break;
    case SceneState::Scene_Config:
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
    case SceneState::Scene_Menu:
        Menu::Draw();
        break;
    case SceneState::Scene_Game:
        Game::Draw();
        break;
    case SceneState::Scene_Config:
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
    case SceneState::Scene_Menu:
        Menu::Initialize();
        break;
    case SceneState::Scene_Game:
        Game::Initialize();
        break;
    case SceneState::Scene_Config:
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
    case SceneState::Scene_Menu:
        Menu::Finalize();
        break;
    case SceneState::Scene_Game:
        Game::Finalize();
        break;
    case SceneState::Scene_Config:
        Config::Finalize();
        break;
    default:
        break;
    }
}
