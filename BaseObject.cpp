#include "BaseObject.h"

BaseObject::BaseObject()
    :posX(0)
    ,posY(0)
    ,scaleX(0)
    ,scaleY(0)
    ,scaling(1.0f)
    ,image(0)
{
}

BaseObject::~BaseObject()
{
}

void BaseObject::Draw()
{
}
