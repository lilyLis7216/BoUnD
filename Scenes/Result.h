#pragma once
#include "../BaseClass/BaseScene.h"

// �O���錾
class FrameRate;

/**
* Result�N���X
* BaseScene���p�����Ă���
*/
class Result : public BaseScene
{
public:
    /**
    * ���U���g�̃R���X�g���N�^
    */
    Result();

    /**
    * ���U���g�̃f�X�g���N�^
    */
    ~Result();

    /**
    * ���U���g��ʂ̍X�V����
    */
    void Update() override;

    /**
    * ���U���g��ʂ̕`�揈��
    */
    void Draw() override;

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

    /** ���F*/
    int whiteCr;

    /** ���F*/
    int yellowCr;

    /** �ԐF�s�G��*/
    int clownRed;

    /** ���F�s�G��*/
    int clownPurple;

    /** ���F�s�G��*/
    int clownSky;

    /** ���F�s�G���̃W�����v�A�j���[�V����*/
    int purpleJump[2];

    /** ���F�s�G���̃W�����v�A�j���[�V����*/
    int skyJump[2];

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

    /** 1��ڂ��ǂ���*/
    bool isFirstPlay;
};