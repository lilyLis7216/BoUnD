#pragma once
#include "../BaseClass/BaseObject.h"

class Player : public BaseObject
{
public:
    /**
    * Player�̃R���X�g���N�^
    */
    Player();

    /**
    * Player�̃f�X�g���N�^
    */
    ~Player();

    /**
    * Player�̍X�V����
    */
    void Update(float deltaTime) override;

    /**
    * Player�̕`�揈��
    */
    void Draw() override;

    /**
    * ���@���s����
    */
    void Miss() { life--; }

    /**
    * �c�@�̎擾
    * 
    * @return int �c�@
    */
    int GetLife() const { return life; }

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

    /** �c�@*/
    int life;

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
