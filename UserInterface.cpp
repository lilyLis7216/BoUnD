#include "UserInterface.h"
#include "DxLib.h"

UserInterface::UserInterface()
{
}

UserInterface::~UserInterface()
{
}

void UserInterface::UIText(int x, int y, int color, const char* str, int num, int fontSize)
{
    SetFontSize(fontSize);
    DrawFormatString(x, y, color, str, num);
}

void UserInterface::UIText(int x, int y, int color, const char* str, int fontSize)
{
    SetFontSize(fontSize);
    DrawString(x, y, str, color);
}
