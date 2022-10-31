#pragma once

// 前方宣言
class Title;
class Game;
class Result;

/**
* SceneManager
* シーン管理クラス
*/
class SceneManager final
{
public:
    /** シーンの状態*/
    enum class SceneState
    {
        Scene_None = 0,  /**< 無し*/
        Scene_Title,     /**< タイトル画面*/
        Scene_Game,      /**< ゲーム画面*/
        Scene_Result,    /**< リザルト画面*/
    };

    /**
    * シーンマネージャーのデストラクタ
    */
    ~SceneManager();

    /**
    * シーンマネージャーのインスタンスの生成
    */
    static void CreateInstance();

    /**
    * シーンマネージャーのインスタンスの削除
    */
    static void DeleteInstance();

    /**
    * シーンマネージャーの更新処理
    */
    static void Update();

    /**
    * シーンマネージャーの描画処理
    */
    static void Draw();

    /**
    * シーンの遷移処理
    * @param[in] nextScene 遷移するシーン
    */
    static void ChangeScene(SceneState nextScene);

private:
    /**
    * シーンマネージャーのコンストラクタ
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

    /** シーンマネージャーのインスタンス*/
    static SceneManager* instance;

    /** 現在のシーンの管理変数*/
    static SceneState nowScene;

    /** 次のシーンの管理変数*/
    static SceneState nextScene;

    /** メニューシーンの管理変数*/
    static Title* menuScene;

    /** ゲームシーンの管理変数*/
    static Game* gameScene;

    /** リザルトシーンの管理変数*/
    static Result* resultScene;
};
