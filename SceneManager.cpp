#include "SceneManager.h"
#include "Menu.h"
#include "Game.h"
#include "Config.h"

SceneManager::SceneState SceneManager::nowScene = SceneManager::SceneState::Scene_Menu;
SceneManager::SceneState SceneManager::nextScene = SceneManager::SceneState::Scene_None;

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
        Menu::Update();
        break;
    case SceneState::Scene_Game:
        Game::Update();
        break;
    case SceneState::Scene_Config:
        Config::Update();
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
        Menu::Draw();
        break;
    case SceneState::Scene_Game:
        Game::Draw();
        break;
    case SceneState::Scene_Config:
        Config::Draw();
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
        Menu::Initialize();
        break;
    case SceneState::Scene_Game:
        Game::Initialize();
        break;
    case SceneState::Scene_Config:
        Config::Initialize();
        break;
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
        Menu::Finalize();
        break;
    case SceneState::Scene_Game:
        Game::Finalize();
        break;
    case SceneState::Scene_Config:
        Config::Finalize();
        break;
    default:
        break;
    }
}
