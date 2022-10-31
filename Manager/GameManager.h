#pragma once

/**
* GameManager
* ゲーム全体の管理クラス
*/
class GameManager final
{
public:
    /**
    * ゲームマネージャーのデストラクタ
    */
    ~GameManager();

    /**
    * ゲームマネージャーのインスタンス生成
    */
    static void CreateInstance();

    /**
    * ゲームマネージャーのインスタンス削除
    */
    static void DeleteInstance();

    /**
    * ゲームマネージャーの更新処理
    * 
    * @param[in] deltaTime 1フレームの経過時間
    */
    static void Update(float deltaTime);

    /**
    * タイマーの取得
    * 
    * @return float タイマーの残り時間
    */
    static float GetTimer() { return timer; }

    /**
    * タイマーの初期化
    */
    static void ResetTimer() { timer = 31.0f; }

    /**
    * スコアの取得
    * 
    * @return 現時点のスコア
    */
    static int GetScore() { return score; }

    /**
    * スコアの加算
    * 
    * @param[in] add 加算するスコアの数値
    */
    static void AddScore(int add) { score += add; }

    /**
    * スコアの初期化
    */
    static void ResetScore() { score = 0; }

    /**
    * コンボ数の取得
    * 
    * @return int 現在のコンボ数
    */
    static int GetComb() { return comb; }

    /**
    * コンボの加算
    */
    static void AddComb() { comb += 1; }

    /**
    * コンボ数の初期化
    */
    static void ResetComb() { comb = 0; }

    /**
    * 最大コンボ数の取得
    * 
    * @return int 現時点の最大コンボ数
    */
    static int GetMaxComb() { return maxComb; }

    /**
    * 最大コンボ数の加算
    */
    static void AddMaxComb();

    /**
    * 最大コンボ数の初期化
    */
    static void ResetMaxComb() { maxComb = 0; }

    /**
    * ゲームルール変数の初期化
    */
    static void ResetAll();

private:
    /**
    * ゲームマネージャーのコンストラクタ
    * シングルトン
    */
    GameManager();

    /** ゲームマネージャーのインスタンス*/
    static GameManager* instance;

    /** タイマー*/
    static float timer;

    /** スコア*/
    static int score;

    /** コンボ数*/
    static int comb;

    /** 最大コンボ数*/
    static int maxComb;
};