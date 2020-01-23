#include "robi.h"

Robi::Robi(std::string FileName, float x, float y) : Entity(FileName,x,y)
{
    this->W = ROBI;
}
