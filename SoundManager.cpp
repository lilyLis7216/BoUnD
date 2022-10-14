#include "SoundManager.h"
#include "DxLib.h"

SoundManager* SoundManager::instance = nullptr;

SoundManager::SoundManager()
{
    instance = this;
    AddSound("Assets/Sound/move.mp3");
    AddSound("Assets/Sound/limit1.mp3");
    AddSound("Assets/Sound/bounce.mp3");
    AddSound("Assets/Sound/falling1.mp3");
    AddSound("Assets/Sound/clash.mp3");
}

SoundManager::~SoundManager()
{
    RemoveAll();
}

void SoundManager::CreateInstance()
{
    if (!instance)
    {
        instance = new SoundManager();
    }
}

void SoundManager::DeleteInstance()
{
    if (instance)
    {
        delete instance;
        instance = nullptr;
    }
}

void SoundManager::AddSound(const char* str)
{
    instance->soundPool.push_back(LoadSoundMem(str));
}

void SoundManager::RemoveAll()
{
    while (!instance->soundPool.empty())
    {
        DeleteSoundMem(instance->soundPool.back());
        instance->soundPool.pop_back();
    }
}

void SoundManager::StartSound(const int SEnum)
{
    int se = instance->soundPool.at(SEnum);
    if (!CheckSoundMem(se))
    {
        PlaySoundMem(se, DX_PLAYTYPE_BACK);
    }
}

void SoundManager::StopSound(const int SEnum)
{
    int se = instance->soundPool.at(SEnum);
    if (CheckSoundMem(se))
    {
        StopSoundMem(se);
    }
}

void SoundManager::StopAll()
{
    for (auto se : instance->soundPool)
    {
        if (CheckSoundMem(se))
        {
            StopSoundMem(se);
        }
    }
}
