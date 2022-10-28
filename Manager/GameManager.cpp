#include "GameManager.h"

/** GameManagerのインスタンス*/
GameManager* GameManager::instance = nullptr;

/** タイマー*/
float GameManager::timer;

/** スコア*/
int GameManager::score;

/** コンボ数*/
int GameManager::comb;

/** 最大コンボ数*/
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
