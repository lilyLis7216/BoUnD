#include "SceneManager.h"
#include "Menu.h"
#include "Game.h"
#include "Result.h"

/** SceneManager�̃C���X�^���X*/
SceneManager* SceneManager::instance = nullptr;

/** ���݂̃V�[���̊Ǘ��ϐ�*/
SceneManager::SceneState SceneManager::nowScene;

/** ���̃V�[���̊Ǘ��ϐ�*/
SceneManager::SceneState SceneManager::nextScene;

/** ���j���[�V�[���̊Ǘ��ϐ�*/
Menu* SceneManager::menuScene;

/** �Q�[���V�[���̊Ǘ��ϐ�*/
Game* SceneManager::gameScene;

/** ���U���g�V�[���̊Ǘ��ϐ�*/
Result* SceneManager::resultScene;

SceneManager::SceneManager()
{
    nowScene  = SceneState::Scene_Menu;
    nextScene = SceneState::Scene_None;
    menuScene = nullptr;
    gameScene = nullptr;
    resultScene = nullptr;
    InitModule(nowScene);
}

SceneManager::~SceneManager()
{
    FinModule(nowScene);
}

void SceneManager::CreateInstance()
{
    if (!instance)
    {
        instance = new SceneManager();
    }
}

void SceneManager::DeleteInstance()
{
    if (instance)
    {
        delete instance;
        instance = nullptr;
    }
}

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
    case SceneState::Scene_Result:
        resultScene->Update();
        break;
    default:
        break;
    }
}

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
    case SceneState::Scene_Result:
        resultScene->Draw();
        break;
    default:
        break;
    }
}

void SceneManager::ChangeScene(SceneState NextScene)
{
    // ���̃V�[�����Z�b�g����
    nextScene = NextScene;
}

void SceneManager::InitModule(SceneState scene)
{
    switch (scene)
    {
    case SceneState::Scene_Menu:
        menuScene = new Menu();
        break;
    case SceneState::Scene_Game:
        gameScene = new Game();
        break;
    case SceneState::Scene_Result:
        resultScene = new Result();
    default:
        break;
    }
}

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
    case SceneState::Scene_Result:
        delete resultScene;
    default:
        break;
    }
}
