#include "Acrobat.h"
#include "DxLib.h"
#include "../Append/Collision.h"
#include "../Manager/GameManager.h"
#include "../Manager/SoundManager.h"
#include "Player.h"
#include "Box.h"

Acrobat::Acrobat(float x)
    : isBound(false)
    , jumpPower(-7.5f)
    , nowHit(false)
    , prevHit(false)
    , animCount(0)
    , animCoolTime(0)
    , animFrame(0)
    , deltaTime(0)
    , isMove(true)
    , isMiss(false)
    , isDead(false)
    , vanishTime(3.0f)
    , resetCombPrevCall(false)
{
    posX = x;
    posY = -100.0f;
    scaleX = 40.0f;
    scaleY = 120.0f;
    halfScaleX = scaleX / 2;
    halfScaleY = scaleY / 2;
    speed = 200.0f;
    LoadDivGraph("Assets/Acrobat/acrobatWalkAnim.png", 2, 2, 1, 86, 134, walkAnim);
    LoadDivGraph("Assets/Acrobat/acrobatSuccessAnim.png", 2, 2, 1, 86, 150, successAnim);
    missGraph = LoadGraph("Assets/Acrobat/miss.png");
    image = walkAnim[0];
    rotate = (float)GetRand(3);
}

Acrobat::~Acrobat()
{
    // image�̌�n��
    image = -1;

    // walkAnim�̌�n��
    for (int i = 0; i < 2; i++)
    {
        DeleteGraph(walkAnim[i]);
    }
}

void Acrobat::Update(float deltaTime, Player* player, Box* box)
{
    // �����o�ϐ���deltaTime�Ɉ�����deltaTime������
    this->deltaTime = deltaTime;

    if (isMove)
    {
        // �ړ�����
        Move();

        // ���t���[����]�ɉ��Z����
        rotate += 0.01f;

        // �v���C���[�Ƃ̓����蔻��
        Collision::CollPtoA(player, this);
    }
    else
    {
        vanishTime -= deltaTime;

        if (vanishTime < 0)
        {
            isDead = true;
        }

        rotate = 0.0f;
    }

    // �A�j���[�V����
    Animation();

    // ���Ƃ̓����蔻��
    Collision::CollBtoA(box, this);

    // �q�b�g�������ǂ�����ۑ�����
    prevHit = nowHit;
}

void Acrobat::Draw()
{
    // �A�N���o�b�g��`�悷��
    DrawRotaGraph((int)posX, (int)posY, scaling, rotate, image, TRUE, TRUE);

    // �f�o�b�O�p���W�\��
    //DrawFormatString(0, 140, GetColor(0, 0, 0), "fallObjX:%5.4f", posX);
    //DrawFormatString(0, 160, GetColor(0, 0, 0), "fallObjY:%5.4f", posY);
}

void Acrobat::OnHit()
{
    // �o�E���h�t���O�𗧂Ă�
    isBound = true;

    // �������Ă����Ԃ�ۑ�����
    nowHit = true;

    // �O�̃t���[���������Ă��Ȃ����
    if (!prevHit)
    {
        // �X�R�A��100���₷
        GameManager::AddScore(100);

        // �R���{�𑝂₷
        GameManager::AddComb();

        // �ő�R���{���𑝂₷
        GameManager::AddMaxComb();

        // ���˂�T�E���h��炷
        SoundManager::StartSound(5);
    }
}

void Acrobat::boxHit()
{
    // �����Ȃ���Ԃɂ���
    isMove = false;

    // �X�R�A��500���₷
    if (!prevHit)
    {
        GameManager::AddScore(500);
        SoundManager::StartSound(7);
        nowHit = true;
    }
}

void Acrobat::Move()
{
    posX += speed * deltaTime;

    if (posY < 835 || 935 < posY)
    {
        isBound = false;
        nowHit = false;
    }

    if (isBound)
    {
        jumpPower = -15.0f;
    }
    else
    {
        jumpPower += 0.2f;
        if (jumpPower > 30)jumpPower = 30;
    }

    if (posY > 935)
    {
        isMove = false;
        isMiss = true;
        if (!resetCombPrevCall)
        {
            GameManager::ResetComb();
            SoundManager::StartSound(6);
            resetCombPrevCall = true;
        }
    }

    // y���ɃW�����v�p���[�����Z����
    posY += jumpPower;
}

void Acrobat::Animation()
{
    animCoolTime -= deltaTime;

    if (animCoolTime <= 0)
    {
        animCount++;

        animCoolTime = 0.5f;
    }

    animFrame = animCount % 2;

    if (isMove)
    {
        image = walkAnim[animFrame];
    }
    else
    {
        if (isMiss)
        {
            image = missGraph;
        }
        else
        {
            image = successAnim[animFrame];
        }
    }
}
