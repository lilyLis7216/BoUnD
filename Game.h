#pragma once
#include "BaseScene.h"

// �O���錾
class FrameRate;
class Player;
class Collision;

class Game : public BaseScene
{
public:
    /**
    * Game�̃R���X�g���N�^
    */
    Game();

    /**
    * Game�̃f�X�g���N�^
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

    /** �����蔻��*/
    Collision* coll;

    /** �f���^�^�C��*/
    float deltaTime;
};
