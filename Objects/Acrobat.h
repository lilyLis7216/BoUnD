#pragma once
#include "../BaseClass/BaseObject.h"

// �O���錾
class Player;
class Box;

/**
* Acrobat�N���X
* BaseObject���p�����Ă���
*/
class Acrobat : public BaseObject
{
public:
    /**
    * �A�N���o�b�g�̃R���X�g���N�^
    */
    Acrobat();

    /**
    * �A�N���o�b�g�̃f�X�g���N�^
    */
    ~Acrobat();

    /**
    * �A�N���o�b�g�̍X�V����
    */
    void Update(float deltaTime, Player* player, Box* box);

    /**
    * �A�N���o�b�g�̕`�揈��
    */
    void Draw() override;

    /**
    * �����������̏���
    * 
    * @param[in] flag �������Ă��邩�ǂ���
    */
    void OnHit();

    /**
    * ���ɓ��B�����Ƃ��̏���
    */
    void boxHit();

    /**
    * �~�X�������ǂ����̎擾
    * 
    * @return isMiss
    */
    bool GetIsMiss() const { return isMiss; }

    /**
    * ����ł��邩�ǂ����̎擾
    * 
    * @return isDead
    */
    bool GetIsDead()const { return isDead; }

private:
    /**
    * �ړ�����
    */
    void Move();

    /**
    * �A�j���[�V��������
    */
    void Animation();

    /** ���˂邩�ǂ���*/
    bool isBound;

    /** ������*/
    float jumpPower;

    /** �O�̃t���[���Ńq�b�g���Ă�����*/
    bool prevHit;

    /** ���̃t���[���Ńq�b�g������*/
    bool nowHit;

    /** �����A�j���[�V����*/
    int walkAnim[2] = { 0 };

    /** �����A�j���[�V����*/
    int successAnim[2] = { 0 };

    /** �A�j���[�V�����J�E���g*/
    int animCount;

    /** �A�j���[�V�����N�[���^�C��*/
    float animCoolTime;

    /** �A�j���[�V�����t���[��*/
    int animFrame;

    /** �f���^�^�C��*/
    float deltaTime;

    /** ��]*/
    float rotate;

    /** �ړ��ł��邩�ǂ���*/
    bool isMove;

    /** �~�X�������ǂ���*/
    bool isMiss;

    /** �~�X���̉摜*/
    int missGraph;

    /** ����ł��邩�ǂ���*/
    bool isDead;

    /** ���Ŏ���*/
    float vanishTime;

    /** �O�t���[���Ń��Z�b�g���Ăяo�������ǂ���*/
    bool resetCombPrevCall;
};
