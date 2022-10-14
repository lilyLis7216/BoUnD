#include "SoundManager.h"
#include "DxLib.h"

SoundManager* SoundManager::instance;
int SoundManager::titleBGM;
int SoundManager::gameBGM;
int SoundManager::resultBGM;
int SoundManager::moveSE;
int SoundManager::moveLimitSE;
int SoundManager::bounceSE;
int SoundManager::fallingSE;
int SoundManager::clashSE;

SoundManager::SoundManager()
{
    instance = nullptr;
    titleBGM = -1;
    gameBGM = -1;
    resultBGM = -1;
    moveSE = LoadSoundMem("Assets/Sound/move.mp3");
    moveLimitSE = LoadSoundMem("Assets/Sound/limit1.mp3");
    bounceSE = LoadSoundMem("Assets/Sound/bounce.mp3");
    fallingSE = LoadSoundMem("Assets/Sound/falling1.mp3");
    clashSE = LoadSoundMem("Assets/Sound/clash.mp3");
}

SoundManager::~SoundManager()
{
    //RemoveAll();
    InitSoundMem();
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

void SoundManager::PlaySE(const int SEnum)
{
    int se = NULL;
    switch (SEnum)
    {
    case 0:
        se = moveSE;
        break;
    case 1:
        se = moveLimitSE;
        break;
    case 2:
        se = bounceSE;
        break;
    case 3:
        se = fallingSE;
        break;
    case 4:
        se = clashSE;
        break;
    default:
        se = -1;
        break;
    }

    if (!CheckSoundMem(se))
    {
        PlaySoundMem(se, DX_PLAYTYPE_BACK);
    }
}

void SoundManager::StopSE(const int SEnum)
{
    int se = NULL;
    switch (SEnum)
    {
    case 0:
        se = moveSE;
        break;
    case 1:
        se = moveLimitSE;
        break;
    case 2:
        se = bounceSE;
        break;
    case 3:
        se = fallingSE;
        break;
    case 4:
        se = clashSE;
        break;
    default:
        se = -1;
        break;
    }

    if (CheckSoundMem(se))
    {
        StopSoundMem(se);
    }
}

//void SoundManager::AddSound(char* str)
//{
//    instance->soundPool.push_back((int*)LoadSoundMem(str));
//}
//
//void SoundManager::RemoveAll()
//{
//    while (!instance->soundPool.empty())
//    {
//        delete instance->soundPool.back();
//        instance->soundPool.pop_back();
//    }
//}
//
//void SoundManager::StartSound(const int SEnum)
//{
//    int se;
//    PlaySoundMem(se, DX_PLAYTYPE_BACK);
//}
//
//void SoundManager::StopSound(const int SEnum)
//{
//}
//
//void SoundManager::StopAll()
//{
//}
