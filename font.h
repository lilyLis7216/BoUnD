#pragma once
#include "DxLib.h"

void LoadFont(LPCSTR fontPath)
{
    if (AddFontResourceEx(fontPath, FR_PRIVATE, NULL) > 0)
    {

    }
    else
    {
        // �t�H���g�ǂݍ��݃G���[����
        MessageBox(NULL, "�t�H���g�Ǎ����s", "", MB_OK);
    }
    //SetFontSize(60);
    //ChangeFont("PixelMplus12", DX_CHARSET_DEFAULT);
    ChangeFont("07�ɂ��܂�t�H���g", DX_CHARSET_DEFAULT);
}

void DeleteFont(LPCSTR fontPath)
{
    if (RemoveFontResourceEx(fontPath, FR_PRIVATE, NULL))
    {

    }
    else
    {
        MessageBox(NULL, "remove failure", "", MB_OK);
    }
}