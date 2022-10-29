#include "GameManager.h"

/** GameManager�̃C���X�^���X*/
GameManager* GameManager::instance = nullptr;

/** �^�C�}�[*/
float GameManager::timer;

/** �X�R�A*/
int GameManager::score;

/** �R���{��*/
int GameManager::comb;

/** �ő�R���{��*/
int GameManager::maxComb;


GameManager::GameManager()
{
    instance = nullptr;

    // �S�Ẵ��Z�b�g
    ResetAll();
}

GameManager::~GameManager()
{
}

void GameManager::CreateInstance()
{
    // �C���X�^���X�̒��g���Ȃ����
    if (!instance)
    {
        // �C���X�^���X�𐶐�����
        instance = new GameManager();
    }
}

void GameManager::DeleteInstance()
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

void GameManager::Update(float deltaTime)
{
    // �^�C�}�[����f���^�^�C��������
    timer -= deltaTime;
}

void GameManager::AddMaxComb()
{
    // ���݂̃R���{�����ő�R���{���𒴂��Ă�����
    if (comb > maxComb)
    {
        // �ő�R���{�������Z����
        maxComb++;
    }
}

void GameManager::ResetAll()
{
    // �^�C�}�[�̃��Z�b�g
    ResetTimer();

    // �X�R�A�̃��Z�b�g
    ResetScore();

    // �R���{�̃��Z�b�g
    ResetComb();

    // �ő�R���{�̃��Z�b�g
    ResetMaxComb();
}
