#include "UserInterface.h"
#include "DxLib.h"

UserInterface::UserInterface()
{
}

UserInterface::~UserInterface()
{
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
    DrawLine(x1, y1 + frameSize / 2, x2, y1 + frameSize / 2, sky, frameSize);  // è„ï”
    DrawLine(x1, y2 - frameSize / 2, x2, y2 - frameSize / 2, sky, frameSize);  // â∫ï”
    DrawLine(x1 + frameSize / 2, y1, x1 + frameSize / 2, y2, sky, frameSize);  // ç∂ï”
    DrawLine(x2 - frameSize / 2, y1, x2 - frameSize / 2, y2, sky, frameSize);  // âEï”
}
