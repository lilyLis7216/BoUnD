#include "AcrobatManager.h"
#include "../Objects/Acrobat.h"
#include "../Objects/Player.h"
#include "GameManager.h"
#include "DxLib.h"

/** AcrobatManager�̃C���X�^���X*/
AcrobatManager* AcrobatManager::instance;

/** Acrobat�̐�*/
int AcrobatManager::acrobatNum;

/** �����̊Ԋu*/
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
    // �C���X�^���X�̒��g���Ȃ����
    if (!instance)
    {
        // �C���X�^���X�𐶐�����
        instance = new AcrobatManager();
    }
}

void AcrobatManager::DeleteInstance()
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

void AcrobatManager::Update(float deltaTime, Player* player, Box* box)
{
    // �����ł����ԂȂ�
    if (IsCreateAcrobat(deltaTime))
    {
        // �A�N���o�b�g�̃C���X�^���X�����
        AddAcrobat(new Acrobat);

        // �N�[���^�C����ݒ肷��
        createInterval = CoolTime();
    }

    // �v�[���S�Ẵ��[�v
    for (int i = 0; i < instance->acrobatPool.size(); i++)
    {
        // pool�Ƀv�[���̏ꏊ��ۑ�����
        auto pool = instance->acrobatPool[i];
        
        // pool�̍X�V
        pool->Update(deltaTime, player, box);
        
        if (pool->GetInBox())
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
    // �v�[���S�Ẵ��[�v
    for (auto pool : instance->acrobatPool)
    {
        // pool�̕`��
        pool->Draw();
    }
}

void AcrobatManager::AddAcrobat(Acrobat* addAcrobat)
{
    // �v�[���̈�Ԍ��ɒǉ�����
    instance->acrobatPool.push_back(addAcrobat);
}

void AcrobatManager::RemoveAcrobat(const int i)
{
    // i�Ԗڂ̃A�N���o�b�g������
    instance->acrobatPool.erase(instance->acrobatPool.begin() + i);
}

void AcrobatManager::RemoveAll()
{
    // �v�[���̒��g���󂶂�Ȃ����
    while (!instance->acrobatPool.empty())
    {
        // �v�[���̈�Ԍ�������
        delete instance->acrobatPool.back();

        //
        instance->acrobatPool.pop_back();
    }
}

bool AcrobatManager::IsCreateAcrobat(float deltaTime)
{
    // �����̃N�[���^�C������f���^�^�C��������
    createInterval -= deltaTime;

    // �����̃N�[���^�C�����Ȃ���Ԃł����݂̐����ő吔��菭�Ȃ��A�c�莞�Ԃ�3�b�ȏ�ł����
    if (createInterval < 0 && acrobatNum < acrobatNumMax && GameManager::GetTimer() > 3.0f)
    {
        // ������������
        return true;
    }
    // �����̋������Ȃ�
    return false;
}

float AcrobatManager::CoolTime()
{
    float ct = 0;

    if (GameManager::GetTimer() > 20.0f)
    {
        ct = 3.0f;
    }
    else if (GameManager::GetTimer() > 10.0f)
    {
        ct = 2.0f;
    }
    else if (GameManager::GetTimer() > 1.0f)
    {
        ct = 1.5f;
    }

    return ct;
}
