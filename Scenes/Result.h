#pragma once
#include "../BaseClass/BaseScene.h"

class Result : public BaseScene
{
public:
    /**
    * Result�̃R���X�g���N�^
    */
    Result();

    /**
    * Result�̃f�X�g���N�^
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
};