#pragma once

class BaseObject
{
public:
    BaseObject();
    virtual ~BaseObject();

    virtual void Update() = 0;
    virtual void Draw();

protected:
    //! x���W
    float posX;
    //! y���W
    float posY;

    //! ����
    float scaleX;
    //! �c��
    float scaleY;
    //! �g��k���p
    float scaling;

    //! �摜
    int image;
};