#include <windows.h>
#include "DxLib.h"
#include "SceneManager.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    // DxLib������
    ChangeWindowMode(TRUE);
    SetGraphMode(1440, 900, 16);
    if (DxLib_Init() == -1)return -1;

    SceneManager* sm = new SceneManager();

    // �Q�[�����[�v
    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        sm->Update();

        //��ʍX�V����
        ClearDrawScreen();

        sm->Draw();
        
        ScreenFlip();
    }

    delete sm;

    DxLib_End();
    return 0;
}