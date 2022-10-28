#include "SoundManager.h"
#include "DxLib.h"

/** SoundManager�̃C���X�^���X*/
SoundManager* SoundManager::instance = nullptr;

SoundManager::SoundManager()
{
    instance = this;
    AddSound("Assets/Sound/title1.mp3");   // 0 �^�C�g��BGM
    AddSound("Assets/Sound/game.mp3");     // 1 �Q�[��BGM
    AddSound("Assets/Sound/result1.mp3");  // 2 ���U���gBGM
    AddSound("Assets/Sound/move.mp3");     // 3 �ړ�SE
    AddSound("Assets/Sound/limit1.mp3");   // 4 �ړ����ESE
    AddSound("Assets/Sound/bounce.mp3");   // 5 ���˂�SE
    AddSound("Assets/Sound/fall1.mp3");    // 6 ����SE
    AddSound("Assets/Sound/clash.mp3");    // 7 ����SE
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
