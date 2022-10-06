#include "SceneManager.h"
#include "Menu.h"
#include "Game.h"
#include "Config.h"
#include "Result.h"

// �Ǘ��ϐ������̏�����
SceneManager::SceneState SceneManager::nowScene = SceneManager::SceneState::Scene_Menu;
SceneManager::SceneState SceneManager::nextScene = SceneManager::SceneState::Scene_None;
Menu* SceneManager::menuScene     = nullptr;
Game* SceneManager::gameScene     = nullptr;
Config* SceneManager::configScene = nullptr;
Result* SceneManager::resultScene = nullptr;

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
        menuScene->Update();
        break;
    case SceneState::Scene_Game:
        gameScene->Update();
        break;
    case SceneState::Scene_Config:
        configScene->Update();
        break;
    case SceneState::Scene_Result:
        resultScene->Update();
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
        menuScene->Draw();
        break;
    case SceneState::Scene_Game:
        gameScene->Draw();
        break;
    case SceneState::Scene_Config:
        configScene->Draw();
        break;
    case SceneState::Scene_Result:
        resultScene->Draw();
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
        menuScene = new Menu();
        break;
    case SceneState::Scene_Game:
        gameScene = new Game();
        break;
    case SceneState::Scene_Config:
        configScene = new Config();
        break;
    case SceneState::Scene_Result:
        resultScene = new Result();
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
        delete menuScene;
        break;
    case SceneState::Scene_Game:
        delete gameScene;
        break;
    case SceneState::Scene_Config:
        delete configScene;
        break;
    case SceneState::Scene_Result:
        delete resultScene;
    default:
        break;
    }
}
