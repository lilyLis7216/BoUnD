#pragma once
#include <vector>

class SoundManager
{
public:

    static void CreateInstance();

    static void DeleteInstance();

    static void PlaySE(const int SEnum);

    static void StopSE(const int SEnum);

    //static void AddSound(char* str);

    //static void RemoveAll();

    //static void StartSound(const int SEnum);

    //static void StopSound(const int SEnum);

    //static void StopAll();

private:
    SoundManager();
    ~SoundManager();

    static SoundManager* instance;

    std::vector<int*> soundPool;

    static int titleBGM;
    static int gameBGM;
    static int resultBGM;
    static int moveSE;
    static int moveLimitSE;
    static int bounceSE;
    static int fallingSE;
    static int clashSE;
};