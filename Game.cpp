#include "Game.h"
#include "DxLib.h"
#include "SceneManager.h"
#include "GameManager.h"
#include "SoundManager.h"
#include "AcrobatManager.h"
#include "Background.h"
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
    bg = new Background();
    frameRate = new FrameRate();
    player = new Player();
    coll = new Collision();
    AcrobatManager::CreateInstance();
}

//--------------------------------------------------------------------------------------------------------------------------------
// @brief �f�X�g���N�^
//--------------------------------------------------------------------------------------------------------------------------------
Game::~Game()
{
    delete bg;
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
    if (player->GetLife() < 0 || GameManager::GetTimer() < 0)
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
    int white = GetColor(255, 255, 255);
    bg->Draw();
    DrawString(0, 0, "�Q�[����ʂł��B", white);
    DrawString(0, 20, "M�L�[�������ƃ��j���[��ʂɖ߂�܂��B", white);

    DrawFormatString(1536, 36, white, "Score:%d", GameManager::GetScore());
    DrawFormatString(1536, 72, white, "Comb:%d", GameManager::GetComb());
    DrawFormatString(1536, 108, white, "Time:%d", (int)GameManager::GetTimer());
    DrawFormatString(1536, 144, white, "FPS:%5.4f", deltaTime);


    AcrobatManager::Draw();

    player->Draw();
}
