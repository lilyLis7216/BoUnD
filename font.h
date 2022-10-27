#pragma once
#include "DxLib.h"

void LoadFont(LPCSTR fontPath)
{
    if (AddFontResourceEx(fontPath, FR_PRIVATE, NULL) > 0)
    {

    }
    else
    {
        // フォント読み込みエラー処理
        MessageBox(NULL, "フォント読込失敗", "", MB_OK);
    }
    SetFontSize(60);
    ChangeFont("07にくまるフォント", DX_CHARSET_DEFAULT);
}

void DeleteFont(LPCSTR fontPath)
{
    if (!RemoveFontResourceEx(fontPath, FR_PRIVATE, NULL))
    {
        MessageBox(NULL, "remove failure", "", MB_OK);
    }
}