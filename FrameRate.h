#pragma once

class FrameRate
{
public:
    FrameRate();
    ~FrameRate();

    void Update();

    float GetDeltaTime() const { return deltaTime; }

private:
    void WaitFrame();

    const int maxFps = 60;
    const int oneFrameTickCount = 1000 / maxFps;

    float deltaTime;
    int prevTime;

};
