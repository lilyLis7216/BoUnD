#pragma once

// 前方宣言
class Menu;
class Game;
class Result;

class SceneManager final
{
public:
    /** シーンの状態*/
    enum class SceneState
    {
        Scene_None = 0,  /**< 無し*/
        Scene_Menu,      /**< メニュー画面*/
        Scene_Game,      /**< ゲーム画面*/
        Scene_Result,    /**< リザルト画面*/
    };

    /**
    * SceneManagerのデストラクタ
    */
    ~SceneManager();

    /**
    * SceneManagerのインスタンスの生成
    */
    static void CreateInstance();

    /**
    * SceneManagerのインスタンスの削除
    */
    static void DeleteInstance();

    /**
    * SceneManagerの更新処理
    */
    static void Update();

    /**
    * SceneManagerの描画処理
    */
    static void Draw();

    /**
    * シーンの遷移処理
    * @param[in] nextScene 遷移するシーン
    */
    static void ChangeScene(SceneState nextScene);

private:
    /**
    * SceneManagerのコンストラクタ
    * シングルトン
    */
    SceneManager();

    /**
    * 指定モジュールの初期化
    *
    * @param[in] scene 初期化するシーン
    */
    static void InitModule(SceneState scene);

    /**
    * 指定モジュールの後始末
    *
    * @param[in] scene 後始末するシーン
    */
    static void FinModule(SceneState scene);

    /** SceneManagerのインスタンス*/
    static SceneManager* instance;

    /** 現在のシーンの管理変数*/
    static SceneState nowScene;

    /** 次のシーンの管理変数*/
    static SceneState nextScene;

    /** メニューシーンの管理変数*/
    static Menu* menuScene;

    /** ゲームシーンの管理変数*/
    static Game* gameScene;

    /** リザルトシーンの管理変数*/
    static Result* resultScene;
};
