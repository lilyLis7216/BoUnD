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

    // 全てのリセット
    ResetAll();
}

GameManager::~GameManager()
{
}

void GameManager::CreateInstance()
{
    // インスタンスの中身がなければ
    if (!instance)
    {
        // インスタンスを生成する
        instance = new GameManager();
    }
}

void GameManager::DeleteInstance()
{
    // インスタンスの中身があれば
    if (instance)
    {
        // インスタンスを削除する
        delete instance;

        // インスタンスの中身をnullptrに設定する
        instance = nullptr;
    }
}

void GameManager::Update(float deltaTime)
{
    // タイマーからデルタタイムを引く
    timer -= deltaTime;
}

void GameManager::AddMaxComb()
{
    // 現在のコンボ数が最大コンボ数を超えていたら
    if (comb > maxComb)
    {
        // 最大コンボ数を加算する
        maxComb++;
    }
}

void GameManager::ResetAll()
{
    // タイマーのリセット
    ResetTimer();

    // スコアのリセット
    ResetScore();

    // コンボのリセット
    ResetComb();

    // 最大コンボのリセット
    ResetMaxComb();
}
