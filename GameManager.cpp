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
    ResetAll();
}

GameManager::~GameManager()
{
}

void GameManager::CreateInstance()
{
    if (!instance)
    {
        instance = new GameManager();
    }
}

void GameManager::DeleteInstance()
{
    if (instance)
    {
        delete instance;
        instance = nullptr;
    }
}

void GameManager::Update(float deltaTime)
{
    timer -= deltaTime;
}

void GameManager::AddMaxComb()
{
    if (comb > maxComb)maxComb++;
}

void GameManager::ResetAll()
{
    ResetTimer();
    ResetScore();
    ResetComb();
    ResetMaxComb();
}
