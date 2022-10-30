#include "Result.h"
#include "DxLib.h"
#include "../Manager/SceneManager.h"
#include "../Manager/SoundManager.h"
#include "../Manager/GameManager.h"
#include "../Append/UserInterface.h"
#include "../Append/FrameRate.h"
#include "../Append/Controller.h"

Result::Result()
    : animCount(0)
    , animCoolTime(0)
    , animFrame(0)
    , deltaTime(0)
    , alpha(100)
    , alphaCoolTime(0.5f)
    , isFirstPlay(false)
{
    // �t���[�����[�g����̃C���X�^���X����
    frameRate = new FrameRate();

    // �w�i�̓ǂݍ���
    backgroundImage = LoadGraph("Assets/Background/result.png");

    // ���F�s�G���̃A�j���[�V�����ǂݍ���
    LoadDivGraph("Assets/Acrobat/clownPurpleAnim.png", 2, 2, 1, 120, 188, purpleIdle);

    // ���F�s�G���̃A�j���[�V�����ǂݍ���
    LoadDivGraph("Assets/Acrobat/clownSkyAnim.png", 2, 2, 1, 120, 188, skyIdle);

    // �ԐF�s�G���̓ǂݍ���
    clownRed = LoadGraph("Assets/Acrobat/p3_16.png");

    // ���F�s�G���̏����摜
    clownPurple = purpleIdle[0];

    // ���F�s�G���̏����摜
    clownSky = purpleIdle[0];

    // ���F
    whiteCr = GetColor(255, 255, 255);

    // ���F
    yellowCr = GetColor(255, 255, 0);
}

Result::~Result()
{
    // �t���[�����[�g����̃C���X�^���X�폜
    delete frameRate;

    // �w�i�̌�n��
    DeleteGraph(backgroundImage);
}

void Result::Update()
{
    // �t���[�����[�g����N���X�̍X�V
    frameRate->Update();

    // �f���^�^�C���̎擾
    deltaTime = frameRate->GetDeltaTime();

    // 1����Đ����Ă��Ȃ����
    if (!isFirstPlay)
    {
        // ���U���gBGM�̍Đ�
        SoundManager::StartSound(2);
        isFirstPlay = true;
    }

    // �L�����̃A�j���[�V����
    CharaAnim();
 
    // ����������
    Fade();

    // M�L�[�܂��̓R���g���[���[��X�{�^����������Ă�����
    if (CheckHitKey(KEY_INPUT_M) || Controller::XInput())
    {
        // �S�ẴT�E���h���~�߂�
        SoundManager::StopAll();

        // �V�[�����^�C�g����ʂɕύX����
        SceneManager::ChangeScene(SceneManager::SceneState::Scene_Title);
    }
}

void Result::Draw()
{
    // �t�H���g�T�C�Y�̎w��
    SetFontSize(100);

    // �w�i�̕\��
    DrawGraph(0, 0, backgroundImage, TRUE);

    // ���U���g��ʂł��邱�Ƃ̕\��
    UserInterface::UIText(400, 160, whiteCr, "  ------Result------  ");

    // ���U���g�\���p�g
    UserInterface::UIBox(400, 1500, 300, 700, 20, GetColor(0, 0, 0), GetColor(0, 255, 255));

    // �ŏI�X�R�A�̕\��
    UserInterface::UIText(500, 350, yellowCr, "Score     %05d", GameManager::GetScore());
    DrawLine(500, 450, 1350, 450, whiteCr, 10);

    // �ő�R���{���̕\��
    UserInterface::UIText(500, 500, yellowCr, "MaxComb     %02d", GameManager::GetMaxComb());
    DrawLine(500, 600, 1350, 600, whiteCr, 10);

    // �ԐF�s�G���\��
    DrawRotaGraph(1570, 460, 1.0f, 0, clownRed, TRUE, TRUE, TRUE);

    // ���F�s�G���\��
    DrawRotaGraph(1600, 850, 2.0f, 0, clownPurple, TRUE);

    // ���F�s�G���\��
    DrawRotaGraph(300, 850, 2.0f, 0, clownSky, TRUE, TRUE);

    // �������`�惂�[�h
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, (int)alpha);

    // �^�C�g����ʂւ̎w���\��
    UserInterface::UIText(600, 850, GetColor(0, 0, 255), "X");
    UserInterface::UIText(700, 850, whiteCr, " to Title");

    // �ʏ�`�惂�[�h�ɖ߂�
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void Result::CharaAnim()
{
    animCoolTime -= deltaTime;

    if (animCoolTime <= 0)
    {
        animCount++;

        animCoolTime = 0.5f;
    }

    animFrame = animCount % 2;

    clownPurple = purpleIdle[animFrame];

    clownSky = skyIdle[animFrame];
}

void Result::Fade()
{
    if (alpha <= 255)
    {
        alpha += deltaTime * 100;

    }
    if (alpha >= 255)
    {
        alphaCoolTime -= deltaTime;

        if (alphaCoolTime <= 0)
        {
            alpha = 100;

            alphaCoolTime = 0.5f;
        }
    }
}
