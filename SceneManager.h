#pragma once

// �O���錾
class Menu;
class Game;
class Config;
class Result;

class SceneManager
{
public:
    enum class SceneState
    {
        Scene_None = 0,  // ����
        Scene_Menu,      // ���j���[���
        Scene_Game,      // �Q�[�����
        Scene_Config,    // �R���t�B�O���
        Scene_Result,    // ���U���g���
    };

    SceneManager();
    ~SceneManager();

    void Update();
    void Draw();

    static void ChangeScene(SceneState nextScene);

    static void InitModule(SceneState scene);  // �w�胂�W���[���̏�����
    static void FinModule(SceneState scene);   // �w�胂�W���[���̌�n��


    //! ���V�[���̊Ǘ��ϐ�
    static SceneState nowScene;

    //! ���̃V�[���̊Ǘ��ϐ�
    static SceneState nextScene;

    //! ���j���[�V�[���Ǘ��ϐ�
    static Menu* menuScene;

    //! �Q�[���V�[���Ǘ��ϐ�
    static Game* gameScene;

    //! �R���t�B�O�V�[���Ǘ��ϐ�
    static Config* configScene;

    //! ���U���g�V�[���Ǘ��ϐ�
    static Result* resultScene;
};
