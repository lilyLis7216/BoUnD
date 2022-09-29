#include "Player.h"
#include "DxLib.h"

//--------------------------------------------------------------------------------------------------------------------------------
// @brief �R���X�g���N�^
//--------------------------------------------------------------------------------------------------------------------------------
Player::Player()
{
    posX = 100;
    posY = 100;
    image = LoadGraph("Assets/Player/test.png");
}

//--------------------------------------------------------------------------------------------------------------------------------
// @brief �f�X�g���N�^
//--------------------------------------------------------------------------------------------------------------------------------
Player::~Player()
{
}

//--------------------------------------------------------------------------------------------------------------------------------
// @brief �v���C���[�X�V����
//--------------------------------------------------------------------------------------------------------------------------------
void Player::Update()
{
    Move();
}

//--------------------------------------------------------------------------------------------------------------------------------
// @brief �v���C���[�`�揈��
//--------------------------------------------------------------------------------------------------------------------------------
void Player::Draw()
{
    DrawRotaGraph((int)posX, (int)posY, scaling, 0, image, FALSE);
}

//--------------------------------------------------------------------------------------------------------------------------------
// @brief �v���C���[�ړ�����
//--------------------------------------------------------------------------------------------------------------------------------
void Player::Move()
{
    if (CheckHitKey(KEY_INPUT_LEFT))
    {
        posX--;
    }

    if (CheckHitKey(KEY_INPUT_RIGHT))
    {
        posX++;
    }
}