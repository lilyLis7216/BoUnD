#include <windows.h>
#include "DxLib.h"
#include "SceneManager.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    // DxLib������
    ChangeWindowMode(TRUE);
    SetGraphMode(1920, 1080, 32);
    if (DxLib_Init() == -1)return -1;

    SceneManager::CreateInstance();

    // �Q�[�����[�v
    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        SceneManager::Update();

        //��ʍX�V����
        ClearDrawScreen();

        SceneManager::Draw();

        ScreenFlip();
    }

    SceneManager::DeleteInstance();

    DxLib_End();
    return 0;
}
