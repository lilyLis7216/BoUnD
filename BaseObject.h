#pragma once

class BaseObject
{
public:
    BaseObject();
    virtual ~BaseObject();

    virtual void Update() = 0;
    virtual void Draw();

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