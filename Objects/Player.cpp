#include "Player.h"
#include "DxLib.h"
#include "../Manager/SoundManager.h"
#include "../Append/Controller.h"

Player::Player()
    : life(3)
    , animCount(0)
    , animFrame(0)
    , deltaTime(0)
{
    posX = 960.0f;
    posY = 910.0f;
    scaleX = 120.0f;
    scaleY = 120.0f;
    halfScaleX = scaleX / 2;
    halfScaleY = scaleY / 2;
    speed = 600.0f;
    LoadDivGraph("Assets/Player/player.png", 2, 2, 1, 400, 217, walkAnim);
    image = walkAnim[0];
}

Player::~Player()
{
    // image�̌�n��
    DeleteGraph(image);
    
    // walkAnim�̌�n��
    for (int i = 0; i < 2; i++)
    {
        DeleteGraph(walkAnim[i]);
    }
}

void Player::Update(float deltaTime)
{
    // �����o�ϐ���deltaTime�Ɉ�����deltaTime������
    this->deltaTime = deltaTime;

    // �ړ�����
    Move();

    // �ʒu��������
    AdjustPos();
}

void Player::Draw()
{
    // �v���C���[�̕`��
    DrawRotaGraph((int)posX, (int)posY, scaling, 0, image, TRUE);
}

void Player::Move()
{
    // ���L�[�܂��̓R���g���[���[�̍����͂������
    if (CheckHitKey(KEY_INPUT_LEFT) || Controller::LeftInput())
    {
        posX -= speed * deltaTime;
        Animation();
    }

    // �E�L�[�܂��̓R���g���[���[�̉E���͂������
    if (CheckHitKey(KEY_INPUT_RIGHT) || Controller::RightInput())
    {
        posX += speed * deltaTime;
        Animation();
    }
}

void Player::AdjustPos()
{
    // ���̐����܂ŗ�����
    if (posX < 420 + halfScaleX)
    {
        posX = 420 + halfScaleX;

        // �ړ���������炷
        SoundManager::StartSound(4);
    }

    // �E�̐����܂ŗ�����
    if (posX > 1500 - halfScaleX)
    {
        posX = 1500 - halfScaleX;

        // �ړ���������炷
        SoundManager::StartSound(4);
    }
}

void Player::Animation()
{
    animCoolTime -= deltaTime;

    if (animCoolTime <= 0)
    {
        animCount++;

        animCoolTime = 0.2f;
    }

    animFrame = animCount % 2;

    image = walkAnim[animFrame];
}
