#include "UserInterface.h"
#include "DxLib.h"

UserInterface* UserInterface::instance = nullptr;

UserInterface::UserInterface()
{
    // フォントの読み込み
    if (AddFontResourceEx("Assets/Font/07Nikumaru.otf", FR_PRIVATE, NULL) > 0)
    {
    }
    else
    {
        // 失敗したときのエラーメッセージ表示
        MessageBox(NULL, "フォント読込失敗", "", MB_OK);
    }
    // デフォルトフォントの変更
    ChangeFont("07にくまるフォント", DX_CHARSET_DEFAULT);
}

UserInterface::~UserInterface()
{
    // フォントの削除
    if (RemoveFontResourceEx("Assets/Font/07Nikumaru.otf", FR_PRIVATE, NULL))
    {
    }
    else
    {
        // 失敗したときのエラーメッセージ表示
        MessageBox(NULL, "remove failure", "", MB_OK);
    }
}

void UserInterface::CreateInstance()
{
    // インスタンスの中身がなければ
    if (!instance)
    {
        // インスタンスを生成する
        instance = new UserInterface();
    }
}

void UserInterface::DeleteInstance()
{
    // インスタンスの中身があれば
    if (instance)
    {
        // インスタンスを削除する
        delete instance;

        // インスタンスの中身をnullptrに設定する
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
    // ベース
    DrawBox(x1, y1, x2, y2, mainCr, TRUE);

    // 上辺
    DrawLine(x1, y1 + frameSize / 2, x2, y1 + frameSize / 2, frameCr, frameSize);

    // 下辺
    DrawLine(x1, y2 - frameSize / 2, x2, y2 - frameSize / 2, frameCr, frameSize);

    // 左辺
    DrawLine(x1 + frameSize / 2, y1, x1 + frameSize / 2, y2, frameCr, frameSize);

    // 右辺
    DrawLine(x2 - frameSize / 2, y1, x2 - frameSize / 2, y2, frameCr, frameSize);
}
