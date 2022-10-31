#pragma once
#include "../BaseClass/BaseScene.h"

// �O���錾
class FrameRate;

/**
* Title�N���X
* BaseScene���p�����Ă���
*/
class Title : public BaseScene
{
public:
    /**
    * �^�C�g���̃R���X�g���N�^
    */
    Title();

    /**
    * �^�C�g���̃f�X�g���N�^
    */
    ~Title();

    /**
    * �^�C�g����ʂ̍X�V����
    */
    void Update() override;

    /**
    * �^�C�g����ʂ̕`�揈��
    */
    void Draw()   override;

private:
    /**
    * �L�����A�j���[�V����
    */
    void CharaAnim();

    /**
    * �t�F�[�h����
    */
    void Fade();

    /** �t���[�����[�g����p*/
    FrameRate* frameRate;

    /** ���S*/
    int logo;

    /** ���F�s�G��*/
    int clownPurple;

    /** ���F�s�G��*/
    int clownSky;

    /** ���F�s�G���̑ҋ@�A�j���[�V����*/
    int purpleIdle[2];

    /** ���F�s�G���̑ҋ@�A�j���[�V����*/
    int skyIdle[2];

    /** �A�j���[�V�����̃J�E���g*/
    int animCount;

    /** �A�j���[�V�����̃N�[���^�C��*/
    float animCoolTime;

    /** �A�j���[�V�����̃t���[��*/
    int animFrame;

    /** �f���^�^�C��*/
    float deltaTime;

    /** �����x*/
    float alpha;

    /** ���������N�[���^�C��*/
    float alphaCoolTime;
};
