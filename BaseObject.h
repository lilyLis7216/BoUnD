#pragma once

class BaseObject
{
public:
    BaseObject();
    virtual ~BaseObject();

    virtual void Update(float deltaTime) = 0;
    virtual void Draw();

    virtual float GetPosX() const { return posX; }
    virtual float GetPosY() const { return posY; }
    virtual float GetScaleX() const { return scaleX; }
    virtual float GetScaleY() const { return scaleY; }

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
