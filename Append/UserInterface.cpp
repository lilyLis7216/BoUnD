#include "UserInterface.h"
#include "DxLib.h"

UserInterface* UserInterface::instance = nullptr;

UserInterface::UserInterface()
{
    // �t�H���g�̓ǂݍ���
    if (AddFontResourceEx("Assets/Font/07Nikumaru.otf", FR_PRIVATE, NULL) > 0)
    {
    }
    else
    {
        // ���s�����Ƃ��̃G���[���b�Z�[�W�\��
        MessageBox(NULL, "�t�H���g�Ǎ����s", "", MB_OK);
    }
    // �f�t�H���g�t�H���g�̕ύX
    ChangeFont("07�ɂ��܂�t�H���g", DX_CHARSET_DEFAULT);
}

UserInterface::~UserInterface()
{
    // �t�H���g�̍폜
    if (RemoveFontResourceEx("Assets/Font/07Nikumaru.otf", FR_PRIVATE, NULL))
    {
    }
    else
    {
        // ���s�����Ƃ��̃G���[���b�Z�[�W�\��
        MessageBox(NULL, "remove failure", "", MB_OK);
    }
}

void UserInterface::CreateInstance()
{
    // �C���X�^���X�̒��g���Ȃ����
    if (!instance)
    {
        // �C���X�^���X�𐶐�����
        instance = new UserInterface();
    }
}

void UserInterface::DeleteInstance()
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

void UserInterface::UIText(int x, int y, int color, const char* str, int num)
{
    DrawFormatString(x, y, color, str, num);
}

void UserInterface::UIText(int x, int y, int color, const char* str)
{
    DrawString(x, y, str, color);
}

void UserInterface::UIBox(int x1, int x2, int y1, int y2, int frameSize, int mainCr, int frameCr)
{
    // �x�[�X
    DrawBox(x1, y1, x2, y2, mainCr, TRUE);

    // ���
    DrawLine(x1, y1 + frameSize / 2, x2, y1 + frameSize / 2, frameCr, frameSize);

    // ����
    DrawLine(x1, y2 - frameSize / 2, x2, y2 - frameSize / 2, frameCr, frameSize);

    // ����
    DrawLine(x1 + frameSize / 2, y1, x1 + frameSize / 2, y2, frameCr, frameSize);

    // �E��
    DrawLine(x2 - frameSize / 2, y1, x2 - frameSize / 2, y2, frameCr, frameSize);
}
