#include "SceneManager.h"
#include "../Scenes/Title.h"
#include "../Scenes/Game.h"
#include "../Scenes/Result.h"

/** �V�[���}�l�[�W���[�̃C���X�^���X*/
SceneManager* SceneManager::instance = nullptr;

/** ���݂̃V�[���̊Ǘ��ϐ�*/
SceneManager::SceneState SceneManager::nowScene;

/** ���̃V�[���̊Ǘ��ϐ�*/
SceneManager::SceneState SceneManager::nextScene;

/** ���j���[�V�[���̊Ǘ��ϐ�*/
Title* SceneManager::menuScene;

/** �Q�[���V�[���̊Ǘ��ϐ�*/
Game* SceneManager::gameScene;

/** ���U���g�V�[���̊Ǘ��ϐ�*/
Result* SceneManager::resultScene;

SceneManager::SceneManager()
{
    // ���݂̃V�[�����^�C�g���ɐݒ肷��
    nowScene  = SceneState::Scene_Title;

    // ���̃V�[�����u�����v�ɐݒ肷��
    nextScene = SceneState::Scene_None;

    // ���j���[�V�[����nullptr��ݒ肷��
    menuScene = nullptr;

    // �Q�[���V�[����nullptr��ݒ肷��
    gameScene = nullptr;

    // ���U���g�V�[����nullptr��ݒ肷��
    resultScene = nullptr;

    // ���݂̃V�[���̏�����
    InitModule(nowScene);
}

SceneManager::~SceneManager()
{
    // ���݂̃V�[���̌�n��
    FinModule(nowScene);
}

void SceneManager::CreateInstance()
{
    // �C���X�^���X�̒��g���Ȃ����
    if (!instance)
    {
        // �C���X�^���X�𐶐�����
        instance = new SceneManager();
    }
}

void SceneManager::DeleteInstance()
{
    // �C���X�^���X�̒��g�������
    if (instance)
    {
        // �C���X�^���X���폜����
        delete instance;

        // �C���X�^���X�̒��g��nullptr�ɐݒ肷��
        instance = nullptr;
    }
}

void SceneManager::Update()
{
    // ���̃V�[�����Z�b�g����Ă�����
    if (nextScene != SceneState::Scene_None)
    {
        // ���݂̃V�[���̏I�����������s
        FinModule(nowScene);

        // ���̃V�[�������݂̃V�[�����Z�b�g
        nowScene = nextScene;

        // ���̃V�[�������N���A
        nextScene = SceneState::Scene_None;
        
        // ���݂̃V�[����������
        InitModule(nowScene);
    }

    // ���݂̃V�[���ɂ���ď����𕪊�
    switch (nowScene)
    {
    case SceneState::Scene_Title:
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
    case SceneState::Scene_Title:
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
    // �w��̃V�[���̃C���X�^���X����
    switch (scene)
    {
    case SceneState::Scene_Title:
        menuScene = new Title();
        break;

    case SceneState::Scene_Game:
        gameScene = new Game();
        break;

    case SceneState::Scene_Result:
        resultScene = new Result();
        break;

    default:
        break;
    }
}

void SceneManager::FinModule(SceneState scene)
{
    // �w��̃V�[���̃C���X�^���X�폜
    switch (scene)
    {
    case SceneState::Scene_Title:
        delete menuScene;
        break;

    case SceneState::Scene_Game:
        delete gameScene;
        break;

    case SceneState::Scene_Result:
        delete resultScene;
        break;

    default:
        break;
    }
}
