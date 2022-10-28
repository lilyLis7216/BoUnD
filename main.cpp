#include <windows.h>
#include "DxLib.h"
#include "Manager/SceneManager.h"
#include "Manager/GameManager.h"
#include "Manager/SoundManager.h"
#include "Append/font.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    // DxLib初期化
    ChangeWindowMode(TRUE);
    SetGraphMode(1920, 1080, 32);
    if (DxLib_Init() == -1)return -1;

    SceneManager::CreateInstance();
    GameManager::CreateInstance();
    SoundManager::CreateInstance();
    LPCSTR fontPath = "Assets/Font/07Nikumaru.otf";
    LoadFont(fontPath);

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
    SoundManager::DeleteInstance();
    DeleteFont(fontPath);

    DxLib_End();
    return 0;
}
