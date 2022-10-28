#pragma once
#include "DxLib.h"

/**
* �t�H���g�̓ǂݍ���
* 
* @param[in] fontPath �t�H���g�̃p�X
*/
void LoadFont(LPCSTR fontPath)
{
    if (AddFontResourceEx(fontPath, FR_PRIVATE, NULL) > 0)
    {

    }
    else
    {
        MessageBox(NULL, "�t�H���g�Ǎ����s", "", MB_OK);
    }
    SetFontSize(60);
    ChangeFont("07�ɂ��܂�t�H���g", DX_CHARSET_DEFAULT);
}

/**
* �t�H���g�̍폜
* 
* @param[in] fontPath �t�H���g�̃p�X
*/
void DeleteFont(LPCSTR fontPath)
{
    if (!RemoveFontResourceEx(fontPath, FR_PRIVATE, NULL))
    {
        MessageBox(NULL, "remove failure", "", MB_OK);
    }
}