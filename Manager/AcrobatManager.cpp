#include "AcrobatManager.h"
#include "../Objects/Acrobat.h"
#include "../Objects/Player.h"
#include "GameManager.h"

/** AcrobatManagerのインスタンス*/
AcrobatManager* AcrobatManager::instance;

/** Acrobatの数*/
int AcrobatManager::acrobatNum;

/** 生成の間隔*/
float AcrobatManager::createInterval;

AcrobatManager::AcrobatManager()
{
    instance = this;
    acrobatNum = 0;
    createInterval = 0.0f;
}

AcrobatManager::~AcrobatManager()
{
    RemoveAll();
}

void AcrobatManager::CreateInstance()
{
    // インスタンスの中身がなければ
    if (!instance)
    {
        // インスタンスを生成する
        instance = new AcrobatManager();
    }
}

void AcrobatManager::DeleteInstance()
{
    // インスタンスの中身があれば
    if (instance)
    {
        // インスタンスを削除する
        delete instance;

        // インスタンスの中身をnullptrに設定する
        instance = nullptr;
    }
}

void AcrobatManager::Update(float deltaTime, Player* player)
{
    // 生成できる状態なら
    if (IsCreateAcrobat(deltaTime))
    {
        // アクロバットのインスタンスを作る
        AddAcrobat(new Acrobat);

        // クールタイムを設定する
        createInterval = 3.5f;
    }

    // プール全てのループ
    for (int i = 0; i < instance->acrobatPool.size(); i++)
    {
        // poolにプールの場所を保存する
        auto pool = instance->acrobatPool[i];
        
        // poolの更新
        pool->Update(deltaTime, player);
        
        if (pool->GetPosX() > 1500)
        {
            RemoveAcrobat(i);
        }
        if (pool->GetPosY() > 1080)
        {
            RemoveAcrobat(i);
            player->Miss();
            GameManager::ResetComb();
        }
    }
}

void AcrobatManager::Draw()
{
    // プール全てのループ
    for (auto pool : instance->acrobatPool)
    {
        // poolの描画
        pool->Draw();
    }
}

void AcrobatManager::AddAcrobat(Acrobat* addAcrobat)
{
    // プールの一番後ろに追加する
    instance->acrobatPool.push_back(addAcrobat);
}

void AcrobatManager::RemoveAcrobat(const int i)
{
    // i番目のアクロバットを消す
    instance->acrobatPool.erase(instance->acrobatPool.begin() + i);
}

void AcrobatManager::RemoveAll()
{
    // プールの中身が空じゃなければ
    while (!instance->acrobatPool.empty())
    {
        // プールの一番後ろを消す
        delete instance->acrobatPool.back();

        //
        instance->acrobatPool.pop_back();
    }
}

bool AcrobatManager::IsCreateAcrobat(float deltaTime)
{
    // 生成のクールタイムからデルタタイムを引く
    createInterval -= deltaTime;

    // 生成のクールタイムがない状態でかつ現在の数が最大数より少なければ
    if (createInterval < 0 && acrobatNum < acrobatNumMax)
    {
        // 生成を許可する
        return true;
    }
    // 生成の許可をしない
    return false;
}