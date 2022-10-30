#pragma once

class BaseObject;
class Player;
class Acrobat;
class Box;

class Collision
{
public:
    /**
    * Collision�̃R���X�g���N�^
    */
    Collision();

    /**
    * Collision�̃f�X�g���N�^
    */
    ~Collision();

    /**
    * �v���C���[�ƃA�N���o�b�g�̋�`�Γ_�����蔻��
    * 
    * @param[out] player �v���C���[
    * @param[out] acrobat �A�N���o�b�g
    */
    static void Coll(Player* player, Acrobat* acrobat);

    /**
    * �v���C���[�ƃA�N���o�b�g�̉~�`�����蔻��
    * 
    * @param[out] player �v���C���[
    * @param[out] acrobat �A�N���o�b�g
    */
    static void CollPtoA(Player* player, Acrobat* acrobat);

    /**
    * ���ƃA�N���o�b�g�̉~�`�����蔻��
    * 
    * @param[out] box ��
    * @param[out] acrobat �A�N���o�b�g
    */
    static void CollBtoA(Box* box, Acrobat* acrobat);
private:
};
