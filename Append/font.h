#pragma once
#include "DxLib.h"

/**
* フォントの読み込み
* 
* @param[in] fontPath フォントのパス
*/
void LoadFont(LPCSTR fontPath)
{
    if (AddFontResourceEx(fontPath, FR_PRIVATE, NULL) > 0)
    {

    }
    else
    {
        MessageBox(NULL, "フォント読込失敗", "", MB_OK);
    }
    SetFontSize(60);
    ChangeFont("07にくまるフォント", DX_CHARSET_DEFAULT);
}

/**
* フォントの削除
* 
* @param[in] fontPath フォントのパス
*/
void DeleteFont(LPCSTR fontPath)
{
    if (!RemoveFontResourceEx(fontPath, FR_PRIVATE, NULL))
    {
        MessageBox(NULL, "remove failure", "", MB_OK);
    }
}