#pragma once
#include <vector>

/**
* SoundManager
* �T�E���h�Ǘ��N���X
*/
class SoundManager
{
public:
    /**
    * �T�E���h�}�l�[�W���[�̃f�X�g���N�^
    */
    ~SoundManager();

    /**
    * �T�E���h�}�l�[�W���[�̃C���X�^���X�̐���
    */
    static void CreateInstance();

    /**
    * �T�E���h�}�l�[�W���[�̃C���X�^���X�̍폜
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
    * �T�E���h�}�l�[�W���[�̃R���X�g���N�^
    * �V���O���g��
    */
    SoundManager();

    /** �T�E���h�}�l�[�W���[�̃C���X�^���X*/
    static SoundManager* instance;

    /** �T�E���h�ۑ��z��*/
    std::vector<int> soundPool;
};