#pragma once
#include "Menu.h"
#include "Game.h"
#include "Config.h"

class SceneManager
{
public:
    enum class SceneState
    {
        Scene_None = 0,  // 無し
        Scene_Menu,      // メニュー画面
        Scene_Game,      // ゲーム画面
        Scene_Config,    // 設定画面
    };

    SceneManager();
    ~SceneManager();

    void Update();
    void Draw();

    static void ChangeScene(SceneState nextScene);

    static void InitModule(SceneState scene);  // 指定モジュールの初期化
    static void FinModule(SceneState scene);   // 指定モジュールの後始末


    //! 現シーンの管理変数
    static SceneState nowScene;

    //! 次のシーンの管理変数
    static SceneState nextScene;

    //! メニューシーン管理変数
    static Menu* menuScene;

    //! ゲームシーン管理変数
    static Game* gameScene;

    //! コンフィグシーン管理変数
    static Config* configScene;
};