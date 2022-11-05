#include "Game.h"
#include "DxLib.h"
#include "../Manager/SceneManager.h"
#include "../Manager/GameManager.h"
#include "../Manager/SoundManager.h"
#include "../Manager/AcrobatManager.h"
#include "../Objects/Player.h"
#include "../Objects/Acrobat.h"
#include "../Objects//Box.h"
#include "../Append/FrameRate.h"
#include "../Append/Collision.h"
#include "../Append/UserInterface.h"

Game::Game()
    :deltaTime(0)
{
    // �Q�[���̃��Z�b�g
    GameManager::ResetAll();

    // �t���[�����[�g����̃C���X�^���X����
    frameRate = new FrameRate();

    // �v���C���[�̃C���X�^���X����
    player = new Player();

    // ���̃C���X�^���X����
    box = new Box();

    // �R���W�����̃C���X�^���X����
    coll = new Collision();

    // �A�N���o�b�g�}�l�[�W���[�̃C���X�^���X����
    AcrobatManager::CreateInstance();

    // �w�i�̓ǂݍ���
    backgroundImage = LoadGraph("Assets/Background/gameBG.png");

    // ���F
    whiteCr = GetColor(255, 255, 255);

    // ���F
    blackCr = GetColor(0, 0, 0);

    // ���F
    skyCr = GetColor(0, 255, 255);
}

Game::~Game()
{
    // �t���[�����[�g����̃C���X�^���X�폜
    delete frameRate;

    // �v���C���[�̃C���X�^���X�폜
    delete player;

    // ���̃C���X�^���X�폜
    delete box;

    // �R���W�����̃C���X�^���X�폜
    delete coll;

    // �A�N���o�b�g�}�l�[�W���[�̃C���X�^���X�폜
    AcrobatManager::DeleteInstance();

    // �w�i�̌�n��
    DeleteGraph(backgroundImage);
}

void Game::Update()
{
    // �t���[�����[�g����N���X�̍X�V
    frameRate->Update();

    // �f���^�^�C���̎擾
    deltaTime = frameRate->GetDeltaTime();

    // �Q�[��BGM�̍Đ�
    SoundManager::StartSound(1);

    // �Q�[���}�l�[�W���[�̍X�V
    GameManager::Update(deltaTime);

    // �v���C���[�̍X�V
    player->Update(deltaTime);

    // �A�N���o�b�^�[�}�l�[�W���[�̍X�V
    AcrobatManager::Update(deltaTime, player, box);

    // M�L�[�������ꂽ�� 
    if (CheckHitKey(KEY_INPUT_M))
    {
        // �S�ẴT�E���h���~�߂�
        SoundManager::StopAll();

        // �V�[�����^�C�g����ʂɕύX
        SceneManager::ChangeScene(SceneManager::SceneState::Scene_Title);
    }

    // R�L�[�������ꂽ�� 
    if (CheckHitKey(KEY_INPUT_R))
    {
        // �S�ẴT�E���h���~�߂�
        SoundManager::StopAll();

        // �V�[�������U���g��ʂɕύX
        SceneManager::ChangeScene(SceneManager::SceneState::Scene_Result);
    }

    // �c�@�������Ȃ邩�A�^�C�}�[��0�ɂȂ�����
    if (player->GetLife() < 1 || GameManager::GetTimer() < 0)
    {
        // �S�ẴT�E���h���~�߂�
        SoundManager::StopAll();

        // �V�[�������U���g��ʂɕύX
        SceneManager::ChangeScene(SceneManager::SceneState::Scene_Result);
    }
}

void Game::Draw()
{
    // �w�i�\��
    DrawGraph(0, 0, backgroundImage, TRUE);

    // ���\��
    box->Draw();

    // �v���C���[�\��
    player->Draw();

    // �A�N���o�b�g�}�l�[�W���[�\��
    AcrobatManager::Draw();

    // UI�\��
    UI();
}

void Game::UI()
{
    // �t�H���g�T�C�Y�̎w��
    SetFontSize(60);

    // �c��^�C���\��
    UserInterface::UIBox(20, 320, 20, 120, 10, blackCr, skyCr);
    UserInterface::UIText(40, 40, whiteCr, "Time:%d", (int)GameManager::GetTimer());

    // �R���{�\��
    UserInterface::UIBox(340, 660, 20, 120, 10, blackCr, skyCr);
    UserInterface::UIText(360, 40, whiteCr, "Comb:%02d", GameManager::GetComb());

    // �ő�R���{�\��
    UserInterface::UIBox(680, 1120, 20, 120, 10, blackCr, skyCr);
    UserInterface::UIText(700, 40, whiteCr, "MaxComb:%02d", GameManager::GetMaxComb());

    // �X�R�A�\��
    UserInterface::UIBox(1140, 1580, 20, 120, 10, blackCr, skyCr);
    UserInterface::UIText(1160, 40, whiteCr, "Score:%05d", GameManager::GetScore());

    // �c�莩�@���\��
    UserInterface::UIBox(1600, 1900, 20, 120, 10, blackCr, skyCr);
    UserInterface::UIText(1620, 40, whiteCr, "Life:%d", player->GetLife());

    // fps�m�F�p
    //DrawFormatString(36, 180, white, "FPS:%5.4f", deltaTime);
}
