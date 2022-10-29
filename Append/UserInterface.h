#pragma once

class UserInterface
{
public:
    /**
    * UserInterface�̃R���X�g���N�^
    */
    UserInterface();

    /**
    * UserInterface�̃f�X�g���N�^
    */
    ~UserInterface();

    /**
    * �e�L�X�g�i���l����j
    * 
    * @param[in] x      x���W
    * @param[in] y      y���W
    * @param[in] color  �\���F
    * @param[in] str    �\��������
    * @param[in] num    �\�����l
    */
    static void UIText(int x, int y, int color, const char* str, int num);

    /**
    * �e�L�X�g�i���l�Ȃ��j
    * 
    * @param[in] x      x���W
    * @param[in] y      y���W
    * @param[in] color  �\���F
    * @param[in] str    �\��������
    */
    static void UIText(int x, int y, int color, const char* str);

    /**
    * �g����
    * 
    * @param[in] x1         �����x���W
    * @param[in] x2         �E����x���W
    * @param[in] y1         �����y���W
    * @param[in] y2         �E����y���W
    * @param[in] frameSize  �g���̑���
    * @param[in] mainCr     �h��ׂ��F
    * @param[in] frameCr    �g�̐F
    */
    static void UIBox(int x1, int x2, int y1, int y2, int frameSize, int mainCr, int frameCr);
};