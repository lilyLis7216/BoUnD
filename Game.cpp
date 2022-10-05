#include "Game.h"
#include "DxLib.h"
#include "SceneManager.h"
#include "FrameRate.h"
#include "Background.h"
#include "FallObj.h"
#include "Collision.h"

Player* Game::player = nullptr;

//--------------------------------------------------------------------------------------------------------------------------------
// @brief �R���X�g���N�^
//--------------------------------------------------------------------------------------------------------------------------------
Game::Game()
{
    player = new Player;
    frameRate = new FrameRate;
    bg = new Background;
    fo = nullptr;
    coll = new Collision;
}

//--------------------------------------------------------------------------------------------------------------------------------
// @brief �f�X�g���N�^
//--------------------------------------------------------------------------------------------------------------------------------
Game::~Game()
{
    delete player;
    delete frameRate;
    delete bg;
    delete coll;
}

//--------------------------------------------------------------------------------------------------------------------------------
// @brief �Q�[���X�V����
//--------------------------------------------------------------------------------------------------------------------------------
void Game::Update()
{
    if (fo == nullptr)
    {
        fo = new FallObj;
    }
    frameRate->Update();
    player->Update(frameRate->GetDeltaTime());
    if (fo != nullptr)
    {
        coll->Coll(player, fo);
    }
    fo->Update(frameRate->GetDeltaTime());
    if (fo->GetPosX() > 1500 || fo->GetPosY() > 1080)
    {
        delete fo;
        fo = nullptr;
    }
    // M�L�[�������ꂽ�� 
    if (CheckHitKey(KEY_INPUT_M))
    {
        // �V�[�������j���[�ɕύX
        SceneManager::ChangeScene(SceneManager::SceneState::Scene_Menu);
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
    DrawFormatString(200, 0, GetColor(255, 255, 255), "FPS:%5.4f", frameRate->GetDeltaTime());

    if (fo != nullptr)fo->Draw();

    player->Draw();
}
