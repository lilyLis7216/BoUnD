#include "AcrobatManager.h"
#include "../Objects/Acrobat.h"
#include "../Objects/Player.h"
#include "GameManager.h"
#include "DxLib.h"
#include <time.h>

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

void AcrobatManager::Update(float deltaTime, Player* player, Box* box)
{
    // 生成できる状態なら
    if (IsCreateAcrobat(deltaTime))
    {
        srand((unsigned int)time(NULL));
        int tmp = (rand() % 29 + 1) * 5 + 150;

        // アクロバットのインスタンスを作る
        AddAcrobat(new Acrobat((float)tmp));

        // アクロバットの数を増やす
        acrobatNum++;

        // クールタイムを設定する
        createInterval = CoolTime();
    }

    // プール全てのループ
    for (int i = 0; i < instance->acrobatPool.size(); i++)
    {
        // poolにプールの場所を保存する
        auto pool = instance->acrobatPool[i];
        
        // poolの更新
        pool->Update(deltaTime, player, box);
        
        if (pool->GetIsDead())
        {
            RemoveAcrobat(i);
            acrobatNum--;
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

    // 生成のクールタイムがない状態でかつ現在の数が最大数より少ければ
    if (createInterval < 0 && acrobatNum < acrobatNumMax)
    {
        // 生成を許可する
        return true;
    }
    // 生成の許可をしない
    return false;
}

float AcrobatManager::CoolTime()
{
    float ct = 0.0f;

    int tmp = rand() % 3;

    if (tmp == 0)
    {
        ct = 5.0f;
    }
    else if (tmp == 1)
    {
        ct = 4.0f;
    }
    else
    {
        ct = 3.0f;
    }


    return ct;
}
