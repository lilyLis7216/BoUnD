#pragma once
#include <vector>

class SoundManager
{
public:
    /**
    * SoundManager�̃f�X�g���N�^
    */
    ~SoundManager();

    /**
    * SoundManager�̃C���X�^���X�̐���
    */
    static void CreateInstance();

    /**
    * SoundManager�̃C���X�^���X�̍폜
    */
    static void DeleteInstance();

    /**
    * �T�E���h�̒ǉ�
    * @param[in] str �T�E���h�ւ̑��΃p�X
    */
    static void AddSound(const char* str);

    /**
    * �S�ẴT�E���h���폜
    */
    static void RemoveAll();

    /**
    * �w��̃T�E���h���Đ�����
    * @param[in] SEnum �T�E���h�̓Y����
    */
    static void StartSound(const int SEnum);

    /**
    * �w��̃T�E���h���~����
    * @param[in] SEnum �T�E���h�̓Y����
    */
    static void StopSound(const int SEnum);

    /**
    * �S�ẴT�E���h���~�߂�
    */
    static void StopAll();

private:
    /**
    * SoundManager�̃R���X�g���N�^
    * �V���O���g��
    */
    SoundManager();

    /** SoundManager�̃C���X�^���X*/
    static SoundManager* instance;

    /** �T�E���h�ۑ��z��*/
    std::vector<int> soundPool;
};