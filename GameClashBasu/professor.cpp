#include "professor.h"

Professor::Professor(std::string FileName, float x, float y) : Entity(FileName,x,y)
{
    this->W = PROFESSOR;
}
