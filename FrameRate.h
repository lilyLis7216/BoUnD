#pragma once

class FrameRate
{
public:
    /**
    * FrameRate�̃R���X�g���N�^
    */
    FrameRate();

    /**
    * FrameRate�̃f�X�g���N�^
    */
    ~FrameRate();

    /**
    * FrameRate�̍X�V����
    */
    void Update();

    /**
    * �f���^�^�C���̎擾
    * 
    * @return float �f���^�^�C��
    */
    float GetDeltaTime() const { return deltaTime; }

private:
    /**
    * fps����֐�
    */
    void WaitFrame();

    /** fps�̏��*/
    const int maxFps = 60;

    /** 1�t���[���̃J�E���g*/
    const int oneFrameTickCount = 1000 / maxFps;

    /** �f���^�^�C��*/
    float deltaTime;

    /** 1�t���[���O�̃^�C��*/
    int prevTime;

};
