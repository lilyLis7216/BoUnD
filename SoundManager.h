#pragma once
#include <vector>

class SoundManager
{
public:

    static void CreateInstance();

    static void DeleteInstance();

    static void AddSound(const char* str);

    static void RemoveAll();

    static void StartSound(const int SEnum);

    static void StopSound(const int SEnum);

    static void StopAll();

private:
    SoundManager();
    ~SoundManager();

    static SoundManager* instance;

    std::vector<int> soundPool;
};