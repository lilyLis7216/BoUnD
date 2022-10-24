#pragma once

// �O���錾
class Menu;
class Game;
class Result;

class SceneManager final
{
public:
    /** �V�[���̏��*/
    enum class SceneState
    {
        Scene_None = 0,  /**< ����*/
        Scene_Menu,      /**< ���j���[���*/
        Scene_Game,      /**< �Q�[�����*/
        Scene_Result,    /**< ���U���g���*/
    };

    /**
    * SceneManager�̃f�X�g���N�^
    */
    ~SceneManager();

    /**
    * SceneManager�̃C���X�^���X�̐���
    */
    static void CreateInstance();

    /**
    * SceneManager�̃C���X�^���X�̍폜
    */
    static void DeleteInstance();

    /**
    * SceneManager�̍X�V����
    */
    static void Update();

    /**
    * SceneManager�̕`�揈��
    */
    static void Draw();

    /**
    * �V�[���̑J�ڏ���
    * @param[in] nextScene �J�ڂ���V�[��
    */
    static void ChangeScene(SceneState nextScene);

private:
    /**
    * SceneManager�̃R���X�g���N�^
    * �V���O���g��
    */
    SceneManager();

    /**
    * �w�胂�W���[���̏�����
    *
    * @param[in] scene ����������V�[��
    */
    static void InitModule(SceneState scene);

    /**
    * �w�胂�W���[���̌�n��
    *
    * @param[in] scene ��n������V�[��
    */
    static void FinModule(SceneState scene);

    /** SceneManager�̃C���X�^���X*/
    static SceneManager* instance;

    /** ���݂̃V�[���̊Ǘ��ϐ�*/
    static SceneState nowScene;

    /** ���̃V�[���̊Ǘ��ϐ�*/
    static SceneState nextScene;

    /** ���j���[�V�[���̊Ǘ��ϐ�*/
    static Menu* menuScene;

    /** �Q�[���V�[���̊Ǘ��ϐ�*/
    static Game* gameScene;

    /** ���U���g�V�[���̊Ǘ��ϐ�*/
    static Result* resultScene;
};
