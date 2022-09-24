#pragma once

class GameScene
{
public:
    // ステート列挙型
    enum State
    {
        DEMO,
        TITLE,
        GAME,
        RESULT
    };

public:
    // コンストラクタ
    GameScene();

    // ステートメソッド
    void Demo();
    void Title();
    void Game();

    // 更新
    bool Update();

private:
    // ステート変数
    State m_state;

    bool m_isEnd;
};