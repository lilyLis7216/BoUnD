#pragma once
#include "../BaseClass/BaseObject.h"

/**
* Box�N���X
* BaseObject���p�����Ă���
*/
class Box : public BaseObject
{
public:

    /**
    * ���̃R���X�g���N�^
    */
    Box();

    /**
    * ���̃f�X�g���N�^
    */
    ~Box();

    /**
    * ���̍X�V
    */
    void Update(float deltaTime) override;

    /**
    * ���̕`��
    */
    void Draw() override;
};