#pragma once
#include <vector>

// �O���錾
class Acrobat;
class Player;

class AcrobatManager
{
public:
    /**
    * AcrobatManager�̃f�X�g���N�^
    */
    ~AcrobatManager();

    /**
    * AcrobatManager�̃C���X�^���X�̐���
    */
    static void CreateInstance();

    /**
    * AcrobatManaer�̃C���X�^���X�̍폜
    */
    static void DeleteInstance();

    /**
    * AcrobatManager�̍X�V����
    * 
    * @param[in] deltaTime 1�t���[���̌o�ߎ���
    * @param[out] player �v���C���[
    */
    static void Update(float deltaTime, Player* player);

    /**
    * AcrobatManaer�̕`�揈��
    */
    static void Draw();

    /**
    * Acrobat�̒ǉ�
    * 
    * @param[out] addAcrobat ��������Acrobat
    */
    static void AddAcrobat(Acrobat* addAcrobat);

    /**
    * Acrobat�̍폜
    * 
    * @param[in] i �폜����Acrobat�̓Y����
    */
    static void RemoveAcrobat(const int i);

    /**
    * �S�Ă�Acrobat�̍폜
    */
    static void RemoveAll();


private:
    /**
    * AcrobatManager�̃R���X�g���N�^
    * �V���O���g��
    */
    AcrobatManager();
    
    /**
    * �������Ă��悢���ǂ���
    * 
    * @param[in] deltaTime 1�t���[���̌o�ߎ���
    */
    static bool IsCreateAcrobat(float deltaTime);

    /** AcrobatManager�̃C���X�^���X*/
    static AcrobatManager* instance;

    /** Acrobat�ۑ��z��*/
    std::vector<Acrobat*> acrobatPool;

    /** AcrobatObject�̍ő吔*/
    static const int acrobatNumMax = 3;

    /** ���݂�AcrobatObject�̐�*/
    static int acrobatNum;

    /** �����̊Ԋu*/
    static float createInterval;
};