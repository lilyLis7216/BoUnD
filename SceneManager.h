#pragma once

class SceneManager
{
public:
    enum class SceneState
    {
        Scene_None = 0,  // ����
        Scene_Menu,      // ���j���[���
        Scene_Game,      // �Q�[�����
        Scene_Config,    // �ݒ���

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
};