#pragma once

class SceneManager
{
public:
    typedef enum SceneState
    {
        Scene_Menu,    // ���j���[���
        Scene_Game,    // �Q�[�����
        Scene_Config,  // �ݒ���

        Scene_None,    // ����
    }SceneState;

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