#pragma once
#include "../BaseClass/BaseScene.h"

class Menu : public BaseScene
{
public:
    /**
    * Menu�̃R���X�g���N�^
    */
    Menu();

    /**
    * Menu�̃f�X�g���N�^
    */
    ~Menu();

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
