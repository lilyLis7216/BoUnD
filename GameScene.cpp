#include "GameScene.h"

GameScene::GameScene()
    :m_state(DEMO)
{
    m_isEnd = false;
}

void GameScene::Demo()
{
    int ret = 0;
    if (ret == 0)
    {
        m_state = TITLE;
    }
}

void GameScene::Title()
{
    int ret = 0;
    if (ret == 0)
    {
        m_isEnd = true;  // 終了
    }
    if (ret == 1)
    {
        m_state = DEMO;  // デモへ
    }
    else if (ret == 2)
    {
        m_state = GAME;  // ゲームへ
    }
}

void GameScene::Game()
{

}

bool GameScene::Update()
{
    switch (m_state)
    {
    case GameScene::DEMO:
        Demo();
        break;
    case GameScene::TITLE:
        Title();
        break;
    case GameScene::GAME:
        Game();
        break;
    case GameScene::RESULT:
        break;
    default:
        break;
    }
    return m_isEnd;
}

