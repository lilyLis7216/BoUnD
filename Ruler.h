#pragma once

class Ruler
{
public:
    Ruler();
    ~Ruler();

    void Update(float deltaTime);

    float GetTimer() const { return timer; }

private:
    float timer;
};