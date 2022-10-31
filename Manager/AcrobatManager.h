#pragma once
#include <vector>

// �O���錾
class Acrobat;
class Player;
class Box;

/**
* AcrobatManager
* �A�N���o�b�g�̊Ǘ��N���X
*/
class AcrobatManager final
{
public:
    /**
    * �A�N���o�b�g�}�l�[�W���[�̃f�X�g���N�^
    */
    ~AcrobatManager();

    /**
    * �A�N���o�b�g�}�l�[�W���[�̃C���X�^���X�̐���
    */
    static void CreateInstance();

    /**
    * �A�N���o�b�g�}�l�[�W���[�̃C���X�^���X�̍폜
    */
    static void DeleteInstance();

    /**
    * �A�N���o�b�g�}�l�[�W���[�̍X�V����
    *
    * @param[in] deltaTime 1�t���[���̌o�ߎ���
    * @param[out] player �v���C���[
    * @param[out] box ��
    */
    static void Update(float deltaTime, Player* player, Box* box);

    /**
    * �A�N���o�b�g�}�l�[�W���[�̕`�揈��
    */
    static void Draw();

    /**
    * �A�N���o�b�g�̒ǉ�
    *
    * @param[out] addAcrobat ��������Acrobat
    */
    static void AddAcrobat(Acrobat* addAcrobat);

    /**
    * �A�N���o�b�g�̍폜
    *
    * @param[in] i �폜����Acrobat�̓Y����
    */
    static void RemoveAcrobat(const int i);

    /**
    * �S�ẴA�N���o�b�g�̍폜
    */
    static void RemoveAll();


private:
    /**
    * �A�N���o�b�g�}�l�[�W���[�̃R���X�g���N�^
    * �V���O���g��
    */
    AcrobatManager();

    /**
    * �������Ă��悢���ǂ���
    *
    * @param[in] deltaTime 1�t���[���̌o�ߎ���
    */
    static bool IsCreateAcrobat(float deltaTime);

    /**
    * �N�[���^�C��
    */
    static void CoolTime(float deltaTime);

    /** �A�N���o�b�g�}�l�[�W���[�̃C���X�^���X*/
    static AcrobatManager* instance;

    /** �A�N���o�b�g�ۑ��z��*/
    std::vector<Acrobat*> acrobatPool;

    /** �A�N���o�b�g�̍ő吔*/
    static const int acrobatNumMax = 3;

    /** ���݂̃A�N���o�b�g�̐�*/
    static int acrobatNum;

    /** �����̊Ԋu*/
    static float createInterval;
};