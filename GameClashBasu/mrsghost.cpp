#include "mrsghost.h"

MrsGhost::MrsGhost(std::string FileName, float x, float y) : Entity(FileName,x,y)
{
    this->W = MRSGHOST;
}
