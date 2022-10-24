#pragma once
#include "BaseObject.h"

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
    * ���������̑傫���̎擾
    * 
    * @return float ���������̑傫��
    */
    float GetHalfScaleX() const { return halfScaleX; }

    /**
    * �c�������̑傫���̎擾
    * 
    * @return float �c�������̑傫��
    */
    float GetHalfScaleY() const { return halfScaleY; }

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

    /** �����̔���*/
    float halfScaleX;

    /** �c���̔���*/
    float halfScaleY;

    /** �c�@*/
    int life;

    /** �f���^�^�C��*/
    float deltaTime;

};
