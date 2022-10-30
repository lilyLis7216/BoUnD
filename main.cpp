#include <windows.h>
#include "DxLib.h"
#include "Manager/SceneManager.h"
#include "Manager/GameManager.h"
#include "Manager/SoundManager.h"
#include "Append/UserInterface.h"
#include "Append/Controller.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    // DxLib初期化
    ChangeWindowMode(TRUE);
    SetGraphMode(1920, 1080, 32);
    if (DxLib_Init() == -1)return -1;

    // シーンマネージャーのインスタンス生成
    SceneManager::CreateInstance();

    // ゲームマネージャーのインスタンス生成
    GameManager::CreateInstance();

    // サウンドマネージャーのインスタンス生成
    SoundManager::CreateInstance();

    // ユーザインターフェースのインスタンス生成
    UserInterface::CreateInstance();

    // コントローラーのインスタンス生成
    Controller::CreateInstance();


    // ゲームループ
    // エラーメッセジがなく、ESCキーが押されておらず、Backボタンの入力がない間ループする
    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0 && !Controller::BackInput())
    {
        // シーンの更新
        SceneManager::Update();

        // コントローラーの更新
        Controller::Update();

        //画面更新処理
        ClearDrawScreen();

        // シーンの描画
        SceneManager::Draw();

        ScreenFlip();
    }

    // コントローラーのインスタンス削除
    Controller::DeleteInstance();

    // ユーザインターフェースのインスタンス削除
    UserInterface::DeleteInstance();

    // サウンドマネージャーのインスタンス削除
    SoundManager::DeleteInstance();

    // ゲームマネージャーのインスタンス削除
    GameManager::DeleteInstance();

    // シーンマネージャーのインスタンス削除
    SceneManager::DeleteInstance();

    DxLib_End();
    return 0;
}
