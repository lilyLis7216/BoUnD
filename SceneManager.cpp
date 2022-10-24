#include "SceneManager.h"
#include "Menu.h"
#include "Game.h"
#include "Result.h"

/** SceneManagerのインスタンス*/
SceneManager* SceneManager::instance = nullptr;

/** 現在のシーンの管理変数*/
SceneManager::SceneState SceneManager::nowScene;

/** 次のシーンの管理変数*/
SceneManager::SceneState SceneManager::nextScene;

/** メニューシーンの管理変数*/
Menu* SceneManager::menuScene;

/** ゲームシーンの管理変数*/
Game* SceneManager::gameScene;

/** リザルトシーンの管理変数*/
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
    // 次のシーンがセットされていたら
    if (nextScene != SceneState::Scene_None)
    {
        FinModule(nowScene);     // 現在のシーンの終了処理を実行
        nowScene = nextScene;    // 次のシーンを現在のシーンをセット
        nextScene = SceneState::Scene_None;  // 次のシーン情報をクリア
        InitModule(nowScene);    // 現在のシーンを初期化
    }

    // 現在のシーンによって処理を分岐
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
    // 現在のシーンによって処理を分岐
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
    // 次のシーンをセットする
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
