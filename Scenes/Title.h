#pragma once
#include "../BaseClass/BaseScene.h"

// �O���錾
class FrameRate;

class Title : public BaseScene
{
public:
    /**
    * Title�̃R���X�g���N�^
    */
    Title();

    /**
    * Title�̃f�X�g���N�^
    */
    ~Title();

    /**
    * ���j���[�̍X�V����
    */
    void Update() override;

    /**
    * ���j���[��ʂ̕`�揈��
    */
    void Draw()   override;

private:
    /**
    * �t�F�[�h����
    */
    void Fade();

    /** �t���[�����[�g����p*/
    FrameRate* frameRate;

    /** ���S*/
    int logo;

    /** �f���^�^�C��*/
    float deltaTime;

    /** �����x*/
    float alpha;

    /** ���������N�[���^�C��*/
    float alphaCoolTime;
};
