#pragma once

/**
* GameManager
* �Q�[���S�̂̊Ǘ��N���X
*/
class GameManager final
{
public:
    /**
    * �Q�[���}�l�[�W���[�̃f�X�g���N�^
    */
    ~GameManager();

    /**
    * �Q�[���}�l�[�W���[�̃C���X�^���X����
    */
    static void CreateInstance();

    /**
    * �Q�[���}�l�[�W���[�̃C���X�^���X�폜
    */
    static void DeleteInstance();

    /**
    * �Q�[���}�l�[�W���[�̍X�V����
    * 
    * @param[in] deltaTime 1�t���[���̌o�ߎ���
    */
    static void Update(float deltaTime);

    /**
    * �^�C�}�[�̎擾
    * 
    * @return float �^�C�}�[�̎c�莞��
    */
    static float GetTimer() { return timer; }

    /**
    * �^�C�}�[�̏�����
    */
    static void ResetTimer() { timer = 31.0f; }

    /**
    * �X�R�A�̎擾
    * 
    * @return �����_�̃X�R�A
    */
    static int GetScore() { return score; }

    /**
    * �X�R�A�̉��Z
    * 
    * @param[in] add ���Z����X�R�A�̐��l
    */
    static void AddScore(int add) { score += add; }

    /**
    * �X�R�A�̏�����
    */
    static void ResetScore() { score = 0; }

    /**
    * �R���{���̎擾
    * 
    * @return int ���݂̃R���{��
    */
    static int GetComb() { return comb; }

    /**
    * �R���{�̉��Z
    */
    static void AddComb() { comb += 1; }

    /**
    * �R���{���̏�����
    */
    static void ResetComb() { comb = 0; }

    /**
    * �ő�R���{���̎擾
    * 
    * @return int �����_�̍ő�R���{��
    */
    static int GetMaxComb() { return maxComb; }

    /**
    * �ő�R���{���̉��Z
    */
    static void AddMaxComb();

    /**
    * �ő�R���{���̏�����
    */
    static void ResetMaxComb() { maxComb = 0; }

    /**
    * �Q�[�����[���ϐ��̏�����
    */
    static void ResetAll();

private:
    /**
    * �Q�[���}�l�[�W���[�̃R���X�g���N�^
    * �V���O���g��
    */
    GameManager();

    /** �Q�[���}�l�[�W���[�̃C���X�^���X*/
    static GameManager* instance;

    /** �^�C�}�[*/
    static float timer;

    /** �X�R�A*/
    static int score;

    /** �R���{��*/
    static int comb;

    /** �ő�R���{��*/
    static int maxComb;
};