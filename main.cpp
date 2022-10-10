#include <windows.h>
#include "DxLib.h"
#include "SceneManager.h"
#include "GameManager.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    // DxLib初期化
    ChangeWindowMode(TRUE);
    SetGraphMode(1920, 1080, 32);
    if (DxLib_Init() == -1)return -1;

    SceneManager::CreateInstance();
    GameManager::CreateInstance();
    

    // ゲームループ
    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        SceneManager::Update();

        //画面更新処理
        ClearDrawScreen();

        SceneManager::Draw();

        ScreenFlip();
    }

    SceneManager::DeleteInstance();
    GameManager::DeleteInstance();

    DxLib_End();
    return 0;
}
