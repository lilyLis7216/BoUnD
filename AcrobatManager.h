#pragma once
#include <vector>

// ‘O•ûéŒ¾
class Acrobat;
class Player;

class AcrobatManager
{
public:

    static void CreateInstance();

    static void DeleteInstance();

    static void Update(float deltaTime, Player* player);

    static void Draw();

    static void AddAcrobat(Acrobat* addAcrobat);

    static void RemoveAcrobat(const int i);

    static void RemoveAll();


private:
    AcrobatManager();
    ~AcrobatManager();
    
    static bool IsCreateAcrobat(float deltaTime);

    static AcrobatManager* instance;

    std::vector<Acrobat*> acrobatPool;

    static const int acrobatNumMax = 3;

    static int acrobatNum;

    static float createInterval;
};