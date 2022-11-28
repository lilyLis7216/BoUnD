#pragma once
#include "../BaseClass/BaseObject.h"

/**
* Player
* BaseObject���p�����Ă���
* �v���C���[�N���X
*/
class Player : public BaseObject
{
public:
    /**
    * �v���C���[�̃R���X�g���N�^
    */
    Player();

    /**
    * �v���C���[�̃f�X�g���N�^
    */
    ~Player();

    /**
    * �v���C���[�̍X�V����
    */
    void Update(float deltaTime) override;

    /**
    * �v���C���[�̕`�揈��
    */
    void Draw() override;

private:
    /**
    * �ړ�����
    */
    void Move();

    /**
    * �ʒu��������
    */
    void AdjustPos();

    /**
    * �A�j���[�V��������
    */
    void Animation();

    /** �����A�j���[�V����*/
    int walkAnim[2] = { 0 };

    /** �A�j���[�V�����̃J�E���g*/
    int animCount;

    /** �A�j���[�V�����̃N�[���^�C��*/
    float animCoolTime;

    /** �A�j���[�V�����̃t���[��*/
    int animFrame;

    /** �f���^�^�C��*/
    float deltaTime;
};
