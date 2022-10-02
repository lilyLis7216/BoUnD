#include "FrameRate.h"
#include "DxLib.h"

FrameRate::FrameRate()
    :deltaTime(0)
    ,prevTime(0)
{
}

FrameRate::~FrameRate()
{
}

void FrameRate::Update()
{
    // fpsが最大値より大きくならないようにする処理
    WaitFrame();

    // デルタタイムの計算
    deltaTime = (GetNowCount() - prevTime) / 1000.0f;

    // デルタタイムを制御
    if (deltaTime >= 0.10f)
    {
        // デルタタイムを0.10fに設定する
        deltaTime = 0.10f;
    }

    // 前フレームとしてここまでかかった時間を保存する
    prevTime = GetNowCount();
}

void FrameRate::WaitFrame()
{
    // 現在地が1フレームにかける時間を超えるまで繰り返す
    while (GetNowCount() < prevTime + oneFrameTickCount);
}
