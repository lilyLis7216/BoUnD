#include "AcrobatManager.h"
#include "Acrobat.h"
#include "Player.h"

AcrobatManager* AcrobatManager::instance;

AcrobatManager::AcrobatManager()
{
    instance = nullptr;
}

AcrobatManager::~AcrobatManager()
{
    RemoveAll();
}

void AcrobatManager::CreateInstance()
{
    if (!instance)
    {
        instance = new AcrobatManager();
    }
}

void AcrobatManager::DeleteInstance()
{
    if (instance)
    {
        delete instance;
        instance = nullptr;
    }
}

void AcrobatManager::Update(float deltaTime, Player* player)
{
    for (auto pool : instance->acrobatPool)
    {
        pool->Update(deltaTime, player);
        if (pool->GetPosX() > 1500 || pool->GetPosY() > 1080)
        {
            RemoveAcrobat();
            AddAcrobat(new Acrobat());
        }
    }
}

void AcrobatManager::Draw()
{
    for (auto pool : instance->acrobatPool)
    {
        pool->Draw();
    }
}

void AcrobatManager::CreatePool(const int num)
{
    for (int i = 0; i < num; i++)
    {
        instance->acrobat = new Acrobat();
        AddAcrobat(instance->acrobat);
    }
}

void AcrobatManager::AddAcrobat(Acrobat* addAcrobat)
{
    instance->acrobatPool.push_back(addAcrobat);
}

void AcrobatManager::RemoveAcrobat()
{
    instance->acrobatPool.pop_back();
}

void AcrobatManager::RemoveAll()
{
    while (!instance->acrobatPool.empty())
    {
        delete instance->acrobatPool.back();
        instance->acrobatPool.pop_back();
    }
}