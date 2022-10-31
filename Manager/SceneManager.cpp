#include "SceneManager.h"
#include "../Scenes/Title.h"
#include "../Scenes/Game.h"
#include "../Scenes/Result.h"

/** シーンマネージャーのインスタンス*/
SceneManager* SceneManager::instance = nullptr;

/** 現在のシーンの管理変数*/
SceneManager::SceneState SceneManager::nowScene;

/** 次のシーンの管理変数*/
SceneManager::SceneState SceneManager::nextScene;

/** メニューシーンの管理変数*/
Title* SceneManager::menuScene;

/** ゲームシーンの管理変数*/
Game* SceneManager::gameScene;

/** リザルトシーンの管理変数*/
Result* SceneManager::resultScene;

SceneManager::SceneManager()
{
    // 現在のシーンをタイトルに設定する
    nowScene  = SceneState::Scene_Title;

    // 次のシーンを「無し」に設定する
    nextScene = SceneState::Scene_None;

    // メニューシーンにnullptrを設定する
    menuScene = nullptr;

    // ゲームシーンにnullptrを設定する
    gameScene = nullptr;

    // リザルトシーンにnullptrを設定する
    resultScene = nullptr;

    // 現在のシーンの初期化
    InitModule(nowScene);
}

SceneManager::~SceneManager()
{
    // 現在のシーンの後始末
    FinModule(nowScene);
}

void SceneManager::CreateInstance()
{
    // インスタンスの中身がなければ
    if (!instance)
    {
        // インスタンスを生成する
        instance = new SceneManager();
    }
}

void SceneManager::DeleteInstance()
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

void SceneManager::Update()
{
    // 次のシーンがセットされていたら
    if (nextScene != SceneState::Scene_None)
    {
        // 現在のシーンの終了処理を実行
        FinModule(nowScene);

        // 次のシーンを現在のシーンをセット
        nowScene = nextScene;

        // 次のシーン情報をクリア
        nextScene = SceneState::Scene_None;
        
        // 現在のシーンを初期化
        InitModule(nowScene);
    }

    // 現在のシーンによって処理を分岐
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
    // 現在のシーンによって処理を分岐
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
    // 次のシーンをセットする
    nextScene = NextScene;
}

void SceneManager::InitModule(SceneState scene)
{
    // 指定のシーンのインスタンス生成
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
    // 指定のシーンのインスタンス削除
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
