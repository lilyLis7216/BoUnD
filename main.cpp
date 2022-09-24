#include <windows.h>
#include "DxLib.h"
#include "SceneManager.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    // DxLib初期化
    ChangeWindowMode(TRUE);
    SetGraphMode(1440, 900, 16);
    if (DxLib_Init() == -1)return -1;

    SceneManager* sm = new SceneManager();

    // ゲームループ
    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        sm->Update();

        //画面更新処理
        ClearDrawScreen();

        sm->Draw();
        
        ScreenFlip();
    }

    delete sm;

    DxLib_End();
    return 0;
}