#pragma once
#include "../BaseClass/BaseScene.h"

// �O���錾
class FrameRate;
class Player;
class Box;
class Collision;

/**
* Game�N���X
* BaseScene���p�����Ă���
*/
class Game : public BaseScene
{
public:
    /**
    * �Q�[���̃R���X�g���N�^
    */
    Game();

    /**
    * �Q�[���̃f�X�g���N�^
    */
    ~Game();

    /**
    * �Q�[����ʂ̍X�V����
    */
    void Update() override;

    /**
    * �Q�[����ʂ̕`�揈��
    */
    void Draw()   override;

    /**
    * Ui����
    */
    void UI();

private:
    /** �t���[�����[�g����p*/
    FrameRate* frameRate;

    /** �v���C���[*/
    Player* player;

    /** ��*/
    Box* box;

    /** �����蔻��*/
    Collision* coll;

    /** �f���^�^�C��*/
    float deltaTime;

    /** ���F*/
    int whiteCr;

    /** ���F*/
    int blackCr;

    /** ���F*/
    int skyCr;
};
