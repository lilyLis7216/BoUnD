#pragma once

/**
* Controller�N���X
*/
class Controller
{
public:
    /**
    * �R���g���[���[�̃R���X�g���N�^
    */
    ~Controller();

    /**
    * �R���g���[���[�̃C���X�^���X����
    */
    static void CreateInstance();

    /**
    * �R���g���[���[�̃C���X�^���X�폜
    */
    static void DeleteInstance();

    /**
    * �R���g���[���[�̍X�V
    */
    static void Update();

    /**
    * �����͂̎擾
    */
    static bool LeftInput() { return leftInput; }

    /**
    * �E���͂̎擾
    */
    static bool RightInput() { return rightInput; }

    /**
    * �X�^�[�g�{�^�����͂̎擾
    */
    static bool StartInput() { return startInput; }

    /**
    * X�{�^�����͂̎擾
    */
    static bool XInput() { return xInput; }

    /**
    * �o�b�N�{�^�����͂̎擾
    */
    static bool BackInput() { return backInput; }

private:
    /**
    * �R���g���[���[�̃R���X�g���N�^
    */
    Controller();

    /** �R���g���[���[�̎���*/
    static Controller* instance;

    /** �R���g���[���[�̓��͏��*/
    static int padState;

    /** ������*/
    static bool leftInput;

    /** �E����*/
    static bool rightInput;

    /** �X�^�[�g�{�^������*/
    static bool startInput;

    /** X�{�^������*/
    static bool xInput;

    /** �o�b�N�{�^������*/
    static bool backInput;
};