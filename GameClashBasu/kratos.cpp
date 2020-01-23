#include "kratos.h"

Kratos::Kratos(std::string FileName, float x, float y) : Entity(FileName,x,y)
{
    this->W = KRATOS;
}
