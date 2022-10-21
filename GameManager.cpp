#include "GameManager.h"

GameManager* GameManager::instance = nullptr;
float GameManager::timer;
int GameManager::score;
int GameManager::comb;
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
