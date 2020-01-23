#include "commander.h"

Commander::Commander(std::string FileName, float x, float y) : Entity(FileName,x,y)
{
    this->W = COMMANDER;
}
