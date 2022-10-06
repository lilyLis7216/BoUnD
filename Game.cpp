#include "Game.h"
#include "DxLib.h"
#include "FrameRate.h"
#include "SceneManager.h"
#include "Background.h"
#include "Acrobat.h"
#include "Collision.h"
#include "Ruler.h"

Player* Game::player = nullptr;

//--------------------------------------------------------------------------------------------------------------------------------
// @brief �R���X�g���N�^
//--------------------------------------------------------------------------------------------------------------------------------
Game::Game()
    :deltaTime(0)
{
    player = new Player();
    frameRate = new FrameRate();
    bg = new Background();
    fo = nullptr;
    coll = new Collision();
    ruler = new Ruler();
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
    delete ruler;
}

//--------------------------------------------------------------------------------------------------------------------------------
// @brief �Q�[���X�V����
//--------------------------------------------------------------------------------------------------------------------------------
void Game::Update()
{
    frameRate->Update();
    deltaTime = frameRate->GetDeltaTime();
    ruler->Update(deltaTime);
    player->Update(deltaTime);

    if (fo == nullptr)
    {
        fo = new Acrobat();
    }
    if (fo != nullptr)
    {
        coll->Coll(player, fo);
    }
    fo->Update(deltaTime);
    if (fo->GetPosX() > 1500 || fo->GetPosY() > 1080)
    {
        delete fo;
        fo = nullptr;
        //player->Miss();
    }
    // M�L�[�������ꂽ�� 
    if (CheckHitKey(KEY_INPUT_M))
    {
        // �V�[�������j���[�ɕύX
        SceneManager::ChangeScene(SceneManager::SceneState::Scene_Menu);
    }
    if (player->GetLife() < 0 || ruler->GetTimer() < 0)
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
    DrawFormatString(0, 40, GetColor(255, 255, 255), "%f", ruler->GetTimer());

    if (fo != nullptr)fo->Draw();

    player->Draw();
}
