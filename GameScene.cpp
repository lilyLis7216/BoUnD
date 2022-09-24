#include "GameScene.h"

GameScene::GameScene()
    :m_state(DEMO)
{
    m_isEnd = false;
}

void GameScene::Demo()
{

}

void GameScene::Title()
{
    int ret = 0;
    if (ret == 0)
    {
        m_isEnd = true;  // èIóπ
    }
    if (ret == 1)
    {
        m_state = DEMO;  // ÉfÉÇÇ÷
    }
    else if (ret == 2)
    {
        m_state = GAME;  // ÉQÅ[ÉÄÇ÷
    }
}

void GameScene::Game()
{

}

bool GameScene::Update()
{
    return 0;
}

