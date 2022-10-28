#include "UserInterface.h"
#include "DxLib.h"

UserInterface::UserInterface()
{
    LPCSTR fontPath = "Assets/Font/07Nikumaru.otf";
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

UserInterface::~UserInterface()
{
    LPCSTR fontPath = "Assets/Font/07Nikumaru.otf";
    if (!RemoveFontResourceEx(fontPath, FR_PRIVATE, NULL))
    {
        MessageBox(NULL, "remove failure", "", MB_OK);
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

void UserInterface::UIBox(int x1, int x2, int y1, int y2, int frameSize)
{
    int sky = GetColor(0, 255, 255);
    int black = GetColor(0, 0, 0);
    DrawBox(x1, y1, x2, y2, black, TRUE);
    DrawLine(x1, y1 + frameSize / 2, x2, y1 + frameSize / 2, sky, frameSize);  // 上辺
    DrawLine(x1, y2 - frameSize / 2, x2, y2 - frameSize / 2, sky, frameSize);  // 下辺
    DrawLine(x1 + frameSize / 2, y1, x1 + frameSize / 2, y2, sky, frameSize);  // 左辺
    DrawLine(x2 - frameSize / 2, y1, x2 - frameSize / 2, y2, sky, frameSize);  // 右辺
}
