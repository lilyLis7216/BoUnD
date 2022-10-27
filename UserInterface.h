#pragma once

class UserInterface
{
public:
    UserInterface();
    ~UserInterface();

    static void UIText(int x, int y, int color, const char* str, int num);
    static void UIText(int x, int y, int color, const char* str);

    static void UIBox(int x1, int x2, int y1, int y2, int frameSize);
};