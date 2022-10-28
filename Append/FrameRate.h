#pragma once

class FrameRate
{
public:
    /**
    * FrameRateのコンストラクタ
    */
    FrameRate();

    /**
    * FrameRateのデストラクタ
    */
    ~FrameRate();

    /**
    * FrameRateの更新処理
    */
    void Update();

    /**
    * デルタタイムの取得
    * 
    * @return float デルタタイム
    */
    float GetDeltaTime() const { return deltaTime; }

private:
    /**
    * fps制御関数
    */
    void WaitFrame();

    /** fpsの上限*/
    const int maxFps = 60;

    /** 1フレームのカウント*/
    const int oneFrameTickCount = 1000 / maxFps;

    /** デルタタイム*/
    float deltaTime;

    /** 1フレーム前のタイム*/
    int prevTime;

};
