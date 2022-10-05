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
    //! xÀ•W
    float posX;
    //! yÀ•W
    float posY;

    //! ‰¡•
    float scaleX;
    //! c•
    float scaleY;
    //! Šg‘åk¬—p
    float scaling;

    //! ‰æ‘œ
    int image;
};
