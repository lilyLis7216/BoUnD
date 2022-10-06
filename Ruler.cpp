#include "Ruler.h"

Ruler::Ruler()
    :timer(60.0f)
{
}

Ruler::~Ruler()
{
}

void Ruler::Update(float deltaTime)
{
    timer -= deltaTime;
}
