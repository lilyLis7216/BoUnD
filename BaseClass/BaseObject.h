#pragma once

class BaseObject
{
public:
    /**
    * BaseObject�̃R���X�g���N�^
    */
    BaseObject();

    /**
    * BaseObject�̃f�X�g���N�^
    */
    virtual ~BaseObject();

    /**
    * BaseObject�X�V�����̉��z�֐�
    * 
    * @param deltaTime 1�t���[���̌o�ߎ���
    */
    virtual void Update(float deltaTime) {};

    /**
    * BaseObject�`�揈���̉��z�֐�
    */
    virtual void Draw() {};

    /**
    * x���W�̎擾
    * 
    * @return float ���݂�x���W
    */
    virtual float GetPosX() const { return posX; }

    /**
    * y���W�̎擾
    * 
    * @return float ���݂�y���W
    */
    virtual float GetPosY() const { return posY; }

    /**
    * �����̎擾
    * 
    * @return float ����
    */
    virtual float GetScaleX() const { return scaleX; }

    /**
    * �c���̎擾
    * 
    * @return float �c��
    */
    virtual float GetScaleY() const { return scaleY; }

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

protected:
    /** x���W*/
    float posX;

    /** y���W*/
    float posY;

    /** ����*/
    float scaleX;

    /** �c��*/
    float scaleY;

    /** �����̔���*/
    float halfScaleX;

    /** �c���̔���*/
    float halfScaleY;

    /** �g�k*/
    float scaling;

    /** ���x*/
    float speed;

    /** �\���摜*/
    int image;
};
