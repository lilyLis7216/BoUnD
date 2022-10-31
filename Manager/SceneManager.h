#pragma once

// �O���錾
class Title;
class Game;
class Result;

/**
* SceneManager
* �V�[���Ǘ��N���X
*/
class SceneManager final
{
public:
    /** �V�[���̏��*/
    enum class SceneState
    {
        Scene_None = 0,  /**< ����*/
        Scene_Title,     /**< �^�C�g�����*/
        Scene_Game,      /**< �Q�[�����*/
        Scene_Result,    /**< ���U���g���*/
    };

    /**
    * �V�[���}�l�[�W���[�̃f�X�g���N�^
    */
    ~SceneManager();

    /**
    * �V�[���}�l�[�W���[�̃C���X�^���X�̐���
    */
    static void CreateInstance();

    /**
    * �V�[���}�l�[�W���[�̃C���X�^���X�̍폜
    */
    static void DeleteInstance();

    /**
    * �V�[���}�l�[�W���[�̍X�V����
    */
    static void Update();

    /**
    * �V�[���}�l�[�W���[�̕`�揈��
    */
    static void Draw();

    /**
    * �V�[���̑J�ڏ���
    * @param[in] nextScene �J�ڂ���V�[��
    */
    static void ChangeScene(SceneState nextScene);

private:
    /**
    * �V�[���}�l�[�W���[�̃R���X�g���N�^
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

    /** �V�[���}�l�[�W���[�̃C���X�^���X*/
    static SceneManager* instance;

    /** ���݂̃V�[���̊Ǘ��ϐ�*/
    static SceneState nowScene;

    /** ���̃V�[���̊Ǘ��ϐ�*/
    static SceneState nextScene;

    /** ���j���[�V�[���̊Ǘ��ϐ�*/
    static Title* menuScene;

    /** �Q�[���V�[���̊Ǘ��ϐ�*/
    static Game* gameScene;

    /** ���U���g�V�[���̊Ǘ��ϐ�*/
    static Result* resultScene;
};
