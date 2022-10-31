#pragma once
#include <vector>

/**
* SoundManager
* サウンド管理クラス
*/
class SoundManager
{
public:
    /**
    * サウンドマネージャーのデストラクタ
    */
    ~SoundManager();

    /**
    * サウンドマネージャーのインスタンスの生成
    */
    static void CreateInstance();

    /**
    * サウンドマネージャーのインスタンスの削除
    */
    static void DeleteInstance();

    /**
    * サウンドの追加
    * @param[in] str サウンドへの相対パス
    */
    static void AddSound(const char* str);

    /**
    * 全てのサウンドを削除
    */
    static void RemoveAll();

    /**
    * 指定のサウンドを再生する
    * @param[in] SEnum サウンドの添え字
    */
    static void StartSound(const int SEnum);

    /**
    * 指定のサウンドを停止する
    * @param[in] SEnum サウンドの添え字
    */
    static void StopSound(const int SEnum);

    /**
    * 全てのサウンドを止める
    */
    static void StopAll();

private:
    /**
    * サウンドマネージャーのコンストラクタ
    * シングルトン
    */
    SoundManager();

    /** サウンドマネージャーのインスタンス*/
    static SoundManager* instance;

    /** サウンド保存配列*/
    std::vector<int> soundPool;
};