#pragma once
#include "../BaseClass/BaseScene.h"

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
    /** ���S*/
    int logo;

    /** �G���^�[�L�[�摜*/
    int enterImage;
};
