#pragma once
#include "../BaseClass/BaseObject.h"

// �O���錾
class Player;
class Box;

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
    void Update(float deltaTime, Player* player, Box* box);

    /**
    * Acrobat�̕`�揈��
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
    void boxHit() { inBox = true; }

    /**
    * ���̒����ǂ����̎擾
    * 
    * @return inBox
    */
    bool GetInBox() const { return inBox; }

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

    /** ���̒����ǂ���*/
    bool inBox;
};
