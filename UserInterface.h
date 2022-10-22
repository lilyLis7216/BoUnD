#pragma once

class UserInterface
{
public:
    UserInterface();
    ~UserInterface();

    static void UIText(int x, int y, int color, const char* str, int num, int fontSize);
    static void UIText(int x, int y, int color, const char* str, int fontSize);
};