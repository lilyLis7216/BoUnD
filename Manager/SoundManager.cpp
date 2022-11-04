#include "SoundManager.h"
#include "DxLib.h"

/** �T�E���h�}�l�[�W���[�̃C���X�^���X*/
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

    AddSound("Assets/Sound/clash.mp3");    // 6 ����SE

    for (auto pool : instance->soundPool)
    {
        // �T�E���h�̃{�����[����100�ɐݒ肷��
        ChangeVolumeSoundMem(100, pool);
    }
}

SoundManager::~SoundManager()
{
    // �S�ẴT�E���h���폜����
    RemoveAll();
}

void SoundManager::CreateInstance()
{
    // �C���X�^���X�̒��g���Ȃ����
    if (!instance)
    {
        // �C���X�^���X�𐶐�����
        instance = new SoundManager();
    }
}

void SoundManager::DeleteInstance()
{
    // �C���X�^���X�̒��g�������
    if (instance)
    {
        // �C���X�^���X���폜����
        delete instance;

        // �C���X�^���X�̒��g��nullptr�ɐݒ肷��
        instance = nullptr;
    }
}

void SoundManager::AddSound(const char* str)
{
    // �v�[���̈�Ԍ��ɒǉ�����
    instance->soundPool.push_back(LoadSoundMem(str));
}

void SoundManager::RemoveAll()
{
    // �v�[�����󂶂�Ȃ����
    while (!instance->soundPool.empty())
    {
        // �v�[���̈�Ԍ��̃T�E���h���폜����
        DeleteSoundMem(instance->soundPool.back());

        // 
        instance->soundPool.pop_back();
    }
}

void SoundManager::StartSound(const int SEnum)
{
    // sound�Ƀv�[���̏ꏊ��ۑ�����
    int sound = instance->soundPool.at(SEnum);

    // sound���Đ�����Ă��Ȃ����
    if (SEnum == 5)
    {
        PlaySoundMem(sound, DX_PLAYTYPE_BACK);
    }
    else if (!CheckSoundMem(sound))
    {
        // sound���Đ�����
        PlaySoundMem(sound, DX_PLAYTYPE_BACK);
    }
}

void SoundManager::StopSound(const int SEnum)
{
    // sound�Ƀv�[���̏ꏊ��ۑ�����
    int sound = instance->soundPool.at(SEnum);

    // sound���Đ�����Ă�����
    if (CheckSoundMem(sound))
    {
        // sound���~����
        StopSoundMem(sound);
    }
}

void SoundManager::StopAll()
{
    // �v�[���S�Ẵ��[�v
    for (auto sound : instance->soundPool)
    {
        // sound���Đ�����Ă�����
        if (CheckSoundMem(sound))
        {
            // sound���~����
            StopSoundMem(sound);
        }
    }
}
