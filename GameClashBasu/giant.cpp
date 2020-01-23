#include "giant.h"

Giant::Giant(std::string FileName, float x, float y) : Entity(FileName , x , y)
{
    this->W = GIANT;
}
