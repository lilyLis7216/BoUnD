#pragma once
#include <vector>

// 前方宣言
class Acrobat;
class Player;
class Box;

/**
* AcrobatManager
* アクロバットの管理クラス
*/
class AcrobatManager final
{
public:
    /**
    * アクロバットマネージャーのデストラクタ
    */
    ~AcrobatManager();

    /**
    * アクロバットマネージャーのインスタンスの生成
    */
    static void CreateInstance();

    /**
    * アクロバットマネージャーのインスタンスの削除
    */
    static void DeleteInstance();

    /**
    * アクロバットマネージャーの更新処理
    *
    * @param[in] deltaTime 1フレームの経過時間
    * @param[out] player プレイヤー
    * @param[out] box 箱
    */
    static void Update(float deltaTime, Player* player, Box* box);

    /**
    * アクロバットマネージャーの描画処理
    */
    static void Draw();

    /**
    * アクロバットの追加
    *
    * @param[out] addAcrobat 生成するAcrobat
    */
    static void AddAcrobat(Acrobat* addAcrobat);

    /**
    * アクロバットの削除
    *
    * @param[in] i 削除するAcrobatの添え字
    */
    static void RemoveAcrobat(const int i);

    /**
    * 全てのアクロバットの削除
    */
    static void RemoveAll();


private:
    /**
    * アクロバットマネージャーのコンストラクタ
    * シングルトン
    */
    AcrobatManager();

    /**
    * 生成してもよいかどうか
    *
    * @param[in] deltaTime 1フレームの経過時間
    */
    static bool IsCreateAcrobat(float deltaTime);

    /**
    * クールタイム
    */
    static void CoolTime(float deltaTime);

    /** アクロバットマネージャーのインスタンス*/
    static AcrobatManager* instance;

    /** アクロバット保存配列*/
    std::vector<Acrobat*> acrobatPool;

    /** アクロバットの最大数*/
    static const int acrobatNumMax = 3;

    /** 現在のアクロバットの数*/
    static int acrobatNum;

    /** 生成の間隔*/
    static float createInterval;
};