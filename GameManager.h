#pragma once

class GameManager final
{
public:
    static void CreateInstance();

    static void DeleteInstance();

    static void Update(float deltaTime);

    static float GetTimer() { return timer; }
    static void ResetTimer() { timer = 60.0f; }

    static void AddScore(int add) { score += add; }
    static void ResetScore() { score = 0; }

    static void AddComb() { comb += 1; }
    static void ResetComb() { comb = 0; }

    static void ResetAll();

private:
    // ƒVƒ“ƒOƒ‹ƒgƒ“
    GameManager();
    ~GameManager();

    static GameManager* instance;

    static float timer;

    static int score;
    
    static int comb;
};