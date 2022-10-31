#include "Controller.h"
#include "DxLib.h"

/** �R���g���[���[�̎���*/
Controller* Controller::instance = nullptr;

/** �R���g���[���[�̓��͏��*/
int Controller::padState;

/** ������*/
bool Controller::leftInput;

/** �E����*/
bool Controller::rightInput;

/** �X�^�[�g�{�^������*/
bool Controller::startInput;

/** X�{�^������*/
bool Controller::xInput;

/** �o�b�N�{�^������*/
bool Controller::backInput;

Controller::Controller()
{
    padState   = NULL;
    leftInput  = NULL;
    rightInput = NULL;
    startInput = NULL;
    xInput     = NULL;
    backInput  = NULL;
}

Controller::~Controller()
{
}

void Controller::CreateInstance()
{
    // �C���X�^���X�̒��g���Ȃ����
    if (!instance)
    {
        // �C���X�^���X�𐶐�����
        instance = new Controller();
    }
}

void Controller::DeleteInstance()
{
    // �C���X�^���X�̒��g�������
    if (instance)
    {
        // �C���X�^���X���폜����
        delete instance;

        // �C���X�^���X�̒��g��nullptr�ɐݒ肷��
        instance = nullptr;
    }
}

void Controller::Update()
{
    padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

    // �\�����̓��̓`�F�b�N
    if ((padState & PAD_INPUT_LEFT) == 0)
    {
        leftInput = false;
    }
    else
    {
        leftInput = true;
    }

    // �\���E�̓��̓`�F�b�N
    if ((padState & PAD_INPUT_RIGHT) == 0)
    {
        rightInput = false;
    }
    else
    {
        rightInput = true;
    }

    // X�{�^���̓��̓`�F�b�N
    if ((padState & PAD_INPUT_1) == 0)
    {
        xInput = false;
    }
    else
    {
        xInput = true;
    }

    // Start�{�^���̓��̓`�F�b�N
    if ((padState & PAD_INPUT_12) == 0)
    {
        startInput = false;
    }
    else
    {
        startInput = true;
    }

    // Back�{�^���̓��̓`�F�b�N
    if ((padState & PAD_INPUT_11) == 0)
    {
        backInput = false;
    }
    else
    {
        backInput = true;
    }
}
