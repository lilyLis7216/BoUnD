#pragma once

class GameScene
{
public:
    // �X�e�[�g�񋓌^
    enum State
    {
        DEMO,
        TITLE,
        GAME,
        RESULT
    };

public:
    // �R���X�g���N�^
    GameScene();

    // �X�e�[�g���\�b�h
    void Demo();
    void Title();
    void Game();

    // �X�V
    bool Update();

private:
    // �X�e�[�g�ϐ�
    State m_state;

    bool m_isEnd;
};