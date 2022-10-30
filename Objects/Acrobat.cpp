#include "Acrobat.h"
#include "DxLib.h"
#include "../Append/Collision.h"
#include "../Manager/GameManager.h"
#include "Player.h"
#include "Box.h"

Acrobat::Acrobat()
    : isBound(false)
    , jumpPower(-7.5f)
    , nowHit(false)
    , prevHit(false)
    , animCount(0)
    , animCoolTime(0)
    , animFrame(0)
    , deltaTime(0)
    , inBox(false)
{
    posX = 300.0f;
    posY = 200.0f;
    scaleX = 40.0f;
    scaleY = 120.0f;
    halfScaleX = scaleX / 2;
    halfScaleY = scaleY / 2;
    speed = 200.0f;
    LoadDivGraph("Assets/Acrobat/acrobat.png", 2, 2, 1, 86, 150, walkAnim);
    image = walkAnim[0];
    rotate = (float)GetRand(3);
}

Acrobat::~Acrobat()
{
    // image�̌�n��
    DeleteGraph(image);

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

    // �ړ�����
    Move();

    // ���t���[����]�ɉ��Z����
    rotate += 0.01f;

    // �A�j���[�V����
    Animation();

    Collision::CollPtoA(player, this);

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

    float tmp = (float)GetRand(5) + 10;

    if (isBound)
    {
        jumpPower = -tmp;
    }
    else
    {
        jumpPower += 0.2f;
        if (jumpPower > 30)jumpPower = 30;
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

        animCoolTime = 1.0f;
    }

    animFrame = animCount % 2;

    image = walkAnim[animFrame];
}
