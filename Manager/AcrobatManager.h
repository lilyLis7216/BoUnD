#pragma once
#include <vector>

// 前方宣言
class Acrobat;
class Player;

class AcrobatManager
{
public:
    /**
    * AcrobatManagerのデストラクタ
    */
    ~AcrobatManager();

    /**
    * AcrobatManagerのインスタンスの生成
    */
    static void CreateInstance();

    /**
    * AcrobatManaerのインスタンスの削除
    */
    static void DeleteInstance();

    /**
    * AcrobatManagerの更新処理
    * 
    * @param[in] deltaTime 1フレームの経過時間
    * @param[out] player プレイヤー
    */
    static void Update(float deltaTime, Player* player);

    /**
    * AcrobatManaerの描画処理
    */
    static void Draw();

    /**
    * Acrobatの追加
    * 
    * @param[out] addAcrobat 生成するAcrobat
    */
    static void AddAcrobat(Acrobat* addAcrobat);

    /**
    * Acrobatの削除
    * 
    * @param[in] i 削除するAcrobatの添え字
    */
    static void RemoveAcrobat(const int i);

    /**
    * 全てのAcrobatの削除
    */
    static void RemoveAll();


private:
    /**
    * AcrobatManagerのコンストラクタ
    * シングルトン
    */
    AcrobatManager();
    
    /**
    * 生成してもよいかどうか
    * 
    * @param[in] deltaTime 1フレームの経過時間
    */
    static bool IsCreateAcrobat(float deltaTime);

    /** AcrobatManagerのインスタンス*/
    static AcrobatManager* instance;

    /** Acrobat保存配列*/
    std::vector<Acrobat*> acrobatPool;

    /** AcrobatObjectの最大数*/
    static const int acrobatNumMax = 3;

    /** 現在のAcrobatObjectの数*/
    static int acrobatNum;

    /** 生成の間隔*/
    static float createInterval;
};