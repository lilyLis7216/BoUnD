#pragma once

/**
* BaseScene
* �V�[���̊��N���X
*/
class BaseScene
{
public:
    /**
    * BaseScene�̃R���X�g���N�^
    */
    BaseScene();

    /**
    * BaseScene�̃f�X�g���N�^
    */
    virtual ~BaseScene();

    /**
    * BaseScene�X�V�����̏����z�֐�
    */
    virtual void Update() = 0;

    /**
    * BaseScene�`�揈���̏����z�֐�
    */
    virtual void Draw() = 0;

protected:
    /** �w�i�摜*/
    int backgroundImage;
};