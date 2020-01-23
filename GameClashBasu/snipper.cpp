#include "snipper.h"

Snipper::Snipper(std::string FileName, float x, float y) : Entity(FileName, x, y)
{
    this->W = SNIPPER;
}
