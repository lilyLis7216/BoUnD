#include "Game.h"
#include "DxLib.h"
#include "SceneManager.h"
#include "GameManager.h"
#include "Background.h"
#include "FrameRate.h"
#include "Player.h"
#include "AcrobatManager.h"
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
    AcrobatManager::CreatePool(1);
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
    frameRate->Update();
    deltaTime = frameRate->GetDeltaTime();

    GameManager::Update(deltaTime);

    player->Update(deltaTime);

    AcrobatManager::Update(deltaTime, player);

    // M�L�[�������ꂽ�� 
    if (CheckHitKey(KEY_INPUT_M))
    {
        // �V�[�������j���[�ɕύX
        SceneManager::ChangeScene(SceneManager::SceneState::Scene_Menu);
    }
    if (player->GetLife() < 0)
    {
        SceneManager::ChangeScene(SceneManager::SceneState::Scene_Result);
    }
}

//--------------------------------------------------------------------------------------------------------------------------------
// @brief �Q�[���`�揈��
//--------------------------------------------------------------------------------------------------------------------------------
void Game::Draw()
{
    bg->Draw();
    DrawString(0, 0, "�Q�[����ʂł��B", GetColor(255, 255, 255));
    DrawString(0, 20, "M�L�[�������ƃ��j���[��ʂɖ߂�܂��B", GetColor(255, 255, 255));
    DrawFormatString(200, 0, GetColor(255, 255, 255), "FPS:%5.4f", deltaTime);
    DrawFormatString(0, 40, GetColor(255, 255, 255), "%f", GameManager::GetTimer());

    AcrobatManager::Draw();

    player->Draw();
}
