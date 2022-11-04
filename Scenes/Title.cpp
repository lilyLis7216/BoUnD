#include "Title.h"
#include "DxLib.h"
#include "../Manager/SceneManager.h"
#include "../Manager/SoundManager.h"
#include "../Append/UserInterface.h"
#include "../Append//FrameRate.h"
#include "../Append/Controller.h"

Title::Title()
    : animCount(0)
    , animCoolTime(0)
    , animFrame(0)
    , deltaTime(0)
    , alpha(100)
    , alphaCoolTime(0.5f)
    , isBound(false)
    , jumpPower(0)
    , logoY(150)
{
    // �t���[�����[�g����̃C���X�^���X����
    frameRate = new FrameRate();

    // �w�i�̓ǂݍ���
    backgroundImage = LoadGraph("Assets/Background/titleBG.png");

    // ���S�̓ǂݍ���
    logo = LoadGraph("Assets/Background/logo.png");

    // ���F�s�G���̃A�j���[�V�����ǂݍ���
    LoadDivGraph("Assets/Acrobat/clownPurpleIdleAnim.png", 2, 2, 1, 120, 188, purpleIdle);

    // ���F�s�G���̃A�j���[�V�����ǂݍ���
    LoadDivGraph("Assets/Acrobat/clownSkyIdleAnim.png", 2, 2, 1, 120, 188, skyIdle);

    // ���F�s�G���̏����摜
    clownPurple = purpleIdle[0];

    // ���F�s�G���̏����摜
    clownSky = skyIdle[0];
}

Title::~Title()
{
    // �t���[�����[�g����̃C���X�^���X�폜
    delete frameRate;

    // �w�i�̌�n��
    DeleteGraph(backgroundImage);

    // ���S�̌�n��
    DeleteGraph(logo);

    for (int i = 0; i < 2; i++)
    {
        // ���F�s�G���ҋ@�̌�n��
        DeleteGraph(purpleIdle[i]);

        // ���F�s�G���ҋ@�̌�n��
        DeleteGraph(skyIdle[i]);
    }

    // ���F�s�G���̌�n��
    clownPurple = -1;

    // ���F�s�G���̌�n��
    clownSky = -1;
}

void Title::Update()
{
    // �t���[�����[�g����N���X�̍X�V
    frameRate->Update();

    // �f���^�^�C���̎擾
    deltaTime = frameRate->GetDeltaTime();

    // �^�C�g��BGM�̍Đ�
    SoundManager::StartSound(0);

    // �L�����̃A�j���[�V����
    CharaAnim();

    // ����������
    Fade();

    // ���S�̓���
    LogoMove();

    // Enter�������ꂽ��
    if (CheckHitKey(KEY_INPUT_RETURN) || Controller::StartInput())
    {
        // �S�ẴT�E���h���~�߂�
        SoundManager::StopAll();

        // �V�[�����Q�[����ʂɕύX
        SceneManager::ChangeScene(SceneManager::SceneState::Scene_Game);
    }
}

void Title::Draw()
{
    // �t�H���g�T�C�Y�̎w��
    SetFontSize(100);

    // �w�i�̕\��
    DrawGraph(0, 0, backgroundImage, TRUE);

    // ���F�s�G���\��
    DrawRotaGraph(1600, 850, 2.0f, 0, clownPurple, TRUE);

    // ���F�s�G���\��
    DrawRotaGraph(300, 850, 2.0f, 0, clownSky, TRUE, TRUE);
    
    // �������`�惂�[�h
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, (int)alpha);

    // �Q�[����ʂւ̎w���\��
    UserInterface::UIText(550, 820, GetColor(0, 0, 0), "Start to  Play!");

    // �ʏ�`�惂�[�h�ɖ߂�
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

    // ���S�̕\��
    DrawRotaGraph(960, (int)logoY, 3.0f, 0, logo, TRUE);
}

void Title::CharaAnim()
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

void Title::Fade()
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

void Title::LogoMove()
{
    if (logoY > 650)
    {
        isBound = true;
    }
    else
    {
        isBound = false;
    }

    if (isBound)
    {
        jumpPower = -14.0f;
    }
    else
    {
        jumpPower += 0.2f;
        if (jumpPower > 30)jumpPower = 30;
    }

    // y���ɃW�����v�p���[�����Z����
    logoY += jumpPower;
}
