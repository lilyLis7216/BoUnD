#pragma once
#include "../BaseClass/BaseObject.h"

class Player;

class Acrobat : public BaseObject
{
public:
    /**
    * Acrobat�̃R���X�g���N�^
    */
    Acrobat();

    /**
    * Acrobat�̃f�X�g���N�^
    */
    ~Acrobat();

    /**
    * Acrobat�̍X�V����
    */
    void Update(float deltaTime) override;
    void Update(float deltaTime, Player* player);

    /**
    * Acrobat�̕`�揈��
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
    * �����������̏���
    * 
    * @param[in] flag �������Ă��邩�ǂ���
    */
    void OnHit(bool flag);

private:
    /** ���˂邩�ǂ���*/
    bool isBound;

    /** ������*/
    float jumpPower;

    /** ���������̑傫��*/
    float halfScaleX;
    /** �c�������̑傫��*/
    float halfScaleY;

    /** �O�̃t���[���Ńq�b�g���Ă�����*/
    bool prevHit;

    /** ���̃t���[���Ńq�b�g������*/
    bool nowHit;
};
