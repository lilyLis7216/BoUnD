#include "Controller.h"
#include "DxLib.h"

Controller* Controller::instance = nullptr;
int Controller::padState;
bool Controller::leftInput;
bool Controller::rightInput;
bool Controller::startInput;
bool Controller::xInput;
bool Controller::backInput;

Controller::Controller()
{
    padState   = NULL;
    leftInput  = NULL;
    rightInput = NULL;
    startInput = NULL;
    xInput     = NULL;
    backInput  = NULL;
}

Controller::~Controller()
{
}

void Controller::CreateInstance()
{
    // インスタンスの中身がなければ
    if (!instance)
    {
        // インスタンスを生成する
        instance = new Controller();
    }
}

void Controller::DeleteInstance()
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

void Controller::Update()
{
    padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

    // 十字左の入力チェック
    if ((padState & PAD_INPUT_LEFT) == 0)
    {
        leftInput = false;
    }
    else
    {
        leftInput = true;
    }

    // 十字右の入力チェック
    if ((padState & PAD_INPUT_RIGHT) == 0)
    {
        rightInput = false;
    }
    else
    {
        rightInput = true;
    }

    // Xボタンの入力チェック
    if ((padState & PAD_INPUT_1) == 0)
    {
        xInput = false;
    }
    else
    {
        xInput = true;
    }

    // Startボタンの入力チェック
    if ((padState & PAD_INPUT_12) == 0)
    {
        startInput = false;
    }
    else
    {
        startInput = true;
    }

    // Backボタンの入力チェック
    if ((padState & PAD_INPUT_11) == 0)
    {
        backInput = false;
    }
    else
    {
        backInput = true;
    }
}
