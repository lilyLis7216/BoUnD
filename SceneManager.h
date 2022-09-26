#pragma once

class SceneManager
{
public:
    typedef enum SceneState
    {
        Scene_Menu,    // メニュー画面
        Scene_Game,    // ゲーム画面
        Scene_Config,  // 設定画面

        Scene_None,    // 無し
    }SceneState;

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
};