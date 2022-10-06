#include "SceneManager.h"
#include "Menu.h"
#include "Game.h"
#include "Config.h"
#include "Result.h"

// 管理変数たちの初期化
SceneManager::SceneState SceneManager::nowScene = SceneManager::SceneState::Scene_Menu;
SceneManager::SceneState SceneManager::nextScene = SceneManager::SceneState::Scene_None;
Menu* SceneManager::menuScene     = nullptr;
Game* SceneManager::gameScene     = nullptr;
Config* SceneManager::configScene = nullptr;
Result* SceneManager::resultScene = nullptr;

//--------------------------------------------------------------------------------------------------------------------------------
// @brief コンストラクタ
//--------------------------------------------------------------------------------------------------------------------------------
SceneManager::SceneManager()
{
    nowScene  = SceneState::Scene_Menu;
    nextScene = SceneState::Scene_None;
    InitModule(nowScene);
}

//--------------------------------------------------------------------------------------------------------------------------------
// @brief デストラクタ
//--------------------------------------------------------------------------------------------------------------------------------
SceneManager::~SceneManager()
{
    FinModule(nowScene);
}

//--------------------------------------------------------------------------------------------------------------------------------
// @brief シーンの更新処理
//--------------------------------------------------------------------------------------------------------------------------------
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
    case SceneState::Scene_Config:
        configScene->Update();
        break;
    case SceneState::Scene_Result:
        resultScene->Update();
        break;
    default:
        break;
    }
}

//--------------------------------------------------------------------------------------------------------------------------------
// @brief シーンの描画処理
//--------------------------------------------------------------------------------------------------------------------------------
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
    case SceneState::Scene_Config:
        configScene->Draw();
        break;
    case SceneState::Scene_Result:
        resultScene->Draw();
        break;
    default:
        break;
    }
}

//--------------------------------------------------------------------------------------------------------------------------------
// @brief 遷移処理
// @param[nextScene] 次のシーン
//--------------------------------------------------------------------------------------------------------------------------------
void SceneManager::ChangeScene(SceneState NextScene)
{
    // 次のシーンをセットする
    nextScene = NextScene;
}

//--------------------------------------------------------------------------------------------------------------------------------
// @brief モジュールの初期化
//--------------------------------------------------------------------------------------------------------------------------------
void SceneManager::InitModule(SceneState scene)
{
    // シーンによって処理を分岐
    switch (scene)
    {
    case SceneState::Scene_Menu:
        menuScene = new Menu();
        break;
    case SceneState::Scene_Game:
        gameScene = new Game();
        break;
    case SceneState::Scene_Config:
        configScene = new Config();
        break;
    case SceneState::Scene_Result:
        resultScene = new Result();
    default:
        break;
    }
}

//--------------------------------------------------------------------------------------------------------------------------------
// @brief モジュールの後始末
//--------------------------------------------------------------------------------------------------------------------------------
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
    case SceneState::Scene_Config:
        delete configScene;
        break;
    case SceneState::Scene_Result:
        delete resultScene;
    default:
        break;
    }
}
