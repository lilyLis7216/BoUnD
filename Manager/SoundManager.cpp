#include "SoundManager.h"
#include "DxLib.h"

/** サウンドマネージャーのインスタンス*/
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

    AddSound("Assets/Sound/clash.mp3");    // 6 激突SE

    for (auto pool : instance->soundPool)
    {
        // サウンドのボリュームを100に設定する
        ChangeVolumeSoundMem(100, pool);
    }
}

SoundManager::~SoundManager()
{
    // 全てのサウンドを削除する
    RemoveAll();
}

void SoundManager::CreateInstance()
{
    // インスタンスの中身がなければ
    if (!instance)
    {
        // インスタンスを生成する
        instance = new SoundManager();
    }
}

void SoundManager::DeleteInstance()
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

void SoundManager::AddSound(const char* str)
{
    // プールの一番後ろに追加する
    instance->soundPool.push_back(LoadSoundMem(str));
}

void SoundManager::RemoveAll()
{
    // プールが空じゃなければ
    while (!instance->soundPool.empty())
    {
        // プールの一番後ろのサウンドを削除する
        DeleteSoundMem(instance->soundPool.back());

        // 
        instance->soundPool.pop_back();
    }
}

void SoundManager::StartSound(const int SEnum)
{
    // soundにプールの場所を保存する
    int sound = instance->soundPool.at(SEnum);

    // soundが再生されていなければ
    if (SEnum == 5)
    {
        PlaySoundMem(sound, DX_PLAYTYPE_BACK);
    }
    else if (!CheckSoundMem(sound))
    {
        // soundを再生する
        PlaySoundMem(sound, DX_PLAYTYPE_BACK);
    }
}

void SoundManager::StopSound(const int SEnum)
{
    // soundにプールの場所を保存する
    int sound = instance->soundPool.at(SEnum);

    // soundが再生されていたら
    if (CheckSoundMem(sound))
    {
        // soundを停止する
        StopSoundMem(sound);
    }
}

void SoundManager::StopAll()
{
    // プール全てのループ
    for (auto sound : instance->soundPool)
    {
        // soundが再生されていたら
        if (CheckSoundMem(sound))
        {
            // soundを停止する
            StopSoundMem(sound);
        }
    }
}
