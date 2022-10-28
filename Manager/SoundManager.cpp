#include "SoundManager.h"
#include "DxLib.h"

/** SoundManagerのインスタンス*/
SoundManager* SoundManager::instance = nullptr;

SoundManager::SoundManager()
{
    instance = this;
    AddSound("Assets/Sound/title1.mp3");   // 0 タイトルBGM
    AddSound("Assets/Sound/game.mp3");     // 1 ゲームBGM
    AddSound("Assets/Sound/result1.mp3");  // 2 リザルトBGM
    AddSound("Assets/Sound/move.mp3");     // 3 移動SE
    AddSound("Assets/Sound/limit1.mp3");   // 4 移動限界SE
    AddSound("Assets/Sound/bounce.mp3");   // 5 跳ねるSE
    AddSound("Assets/Sound/fall1.mp3");    // 6 落下SE
    AddSound("Assets/Sound/clash.mp3");    // 7 激突SE
    for (auto pool : instance->soundPool)
    {
        ChangeVolumeSoundMem(100, pool);
    }
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
