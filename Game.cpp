#include "Game.h"
#include "DxLib.h"
#include "SceneManager.h"
#include "GameManager.h"
#include "SoundManager.h"
#include "AcrobatManager.h"
#include "FrameRate.h"
#include "Player.h"
#include "Acrobat.h"
#include "Collision.h"

//--------------------------------------------------------------------------------------------------------------------------------
// @brief �R���X�g���N�^
//--------------------------------------------------------------------------------------------------------------------------------
Game::Game()
    :deltaTime(0)
{
    GameManager::ResetAll();
    frameRate = new FrameRate();
    player = new Player();
    coll = new Collision();
    AcrobatManager::CreateInstance();
    backgroundImage = LoadGraph("Assets/Background/test.png");
}

//--------------------------------------------------------------------------------------------------------------------------------
// @brief �f�X�g���N�^
//--------------------------------------------------------------------------------------------------------------------------------
Game::~Game()
{
    delete frameRate;
    delete player;
    delete coll;
    AcrobatManager::DeleteInstance();
}

//--------------------------------------------------------------------------------------------------------------------------------
// @brief �Q�[���X�V����
//--------------------------------------------------------------------------------------------------------------------------------
void Game::Update()
{
    SoundManager::StartSound(1);

    frameRate->Update();
    deltaTime = frameRate->GetDeltaTime();
    GameManager::Update(deltaTime);
    player->Update(deltaTime);
    AcrobatManager::Update(deltaTime, player);

    // M�L�[�������ꂽ�� 
    if (CheckHitKey(KEY_INPUT_M))
    {
        SoundManager::StopAll();
        // �V�[�������j���[�ɕύX
        SceneManager::ChangeScene(SceneManager::SceneState::Scene_Menu);
    }
    if (player->GetLife() < 1 || GameManager::GetTimer() < 0)
    {
        SoundManager::StopAll();
        SceneManager::ChangeScene(SceneManager::SceneState::Scene_Result);
    }
}

//--------------------------------------------------------------------------------------------------------------------------------
// @brief �Q�[���`�揈��
//--------------------------------------------------------------------------------------------------------------------------------
void Game::Draw()
{
    DrawGraph(0, 0, backgroundImage, TRUE);
    AcrobatManager::Draw();
    player->Draw();
    UI();
}

void Game::UI()
{
    int fontSize = 60;
    int white = GetColor(255, 255, 255);
    DrawFormatString(1518, fontSize, white, "Score:%d", GameManager::GetScore());
    DrawFormatString(1518, fontSize * 2, white, "Comb:%d", GameManager::GetComb());
    DrawFormatString(1518, fontSize * 3, white, "MaxComb:%d", GameManager::GetMaxComb());
    DrawFormatString(36, fontSize, white, "Time:%d", (int)GameManager::GetTimer());
    DrawFormatString(36, fontSize * 2, white, "Life:%d", player->GetLife());
    DrawFormatString(36, fontSize * 3, white, "FPS:%5.4f", deltaTime);
}
