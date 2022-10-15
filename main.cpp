#include <windows.h>
#include "DxLib.h"
#include "SceneManager.h"
#include "GameManager.h"
#include "SoundManager.h"
#include "font.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    // DxLib������
    ChangeWindowMode(TRUE);
    SetGraphMode(1920, 1080, 32);
    if (DxLib_Init() == -1)return -1;

    SceneManager::CreateInstance();
    GameManager::CreateInstance();
    SoundManager::CreateInstance();
    LPCSTR fontPath = "Assets/Font/PixelMplus12-Regular.ttf";
    LoadFont(fontPath);

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
    GameManager::DeleteInstance();
    SoundManager::DeleteInstance();
    DeleteFont(fontPath);

    DxLib_End();
    return 0;
}
