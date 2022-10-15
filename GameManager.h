#pragma once

class GameManager final
{
public:
    static void CreateInstance();

    static void DeleteInstance();

    static void Update(float deltaTime);

    static float GetTimer() { return timer; }
    static void ResetTimer() { timer = 30.0f; }

    static int GetScore() { return score; }
    static void AddScore(int add) { score += add; }
    static void ResetScore() { score = 0; }

    static int GetComb() { return comb; }
    static void AddComb() { comb += 1; }
    static void ResetComb() { comb = 0; }

    static void ResetAll();

private:
    // シングルトン
    GameManager();
    ~GameManager();

    static GameManager* instance;

    static float timer;

    static int score;
    
    static int comb;
};