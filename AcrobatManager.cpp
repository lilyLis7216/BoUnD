#include "AcrobatManager.h"
#include "Acrobat.h"
#include "Player.h"

AcrobatManager* AcrobatManager::instance;
int AcrobatManager::acrobatNum;
float AcrobatManager::createInterval;

AcrobatManager::AcrobatManager()
{
    instance = nullptr;
    acrobatNum = 0;
    createInterval = 0.0f;
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
    if (IsCreateAcrobat(deltaTime))
    {
        AddAcrobat(new Acrobat);
        createInterval = 5.0f;
    }
    for (int i = 0; i < instance->acrobatPool.size(); i++)
    {
        auto pool = instance->acrobatPool[i];
        pool->Update(deltaTime, player);
        if (pool->GetPosX() > 1500 || pool->GetPosY() > 1080)
        {
            RemoveAcrobat(i);
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

void AcrobatManager::AddAcrobat(Acrobat* addAcrobat)
{
    instance->acrobatPool.push_back(addAcrobat);
}

void AcrobatManager::RemoveAcrobat(const int i)
{
    //instance->acrobatPool.pop_back();
    instance->acrobatPool.erase(instance->acrobatPool.begin() + i);
}

void AcrobatManager::RemoveAll()
{
    while (!instance->acrobatPool.empty())
    {
        delete instance->acrobatPool.back();
        instance->acrobatPool.pop_back();
    }
}

bool AcrobatManager::IsCreateAcrobat(float deltaTime)
{
    createInterval -= deltaTime;
    if (createInterval < 0 && acrobatNum < acrobatNumMax)
    {
        return true;
    }
    return false;
}