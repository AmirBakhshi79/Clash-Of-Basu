#ifndef COMMANDER_H
#define COMMANDER_H

#include "entity.h"
class Commander : public Entity
{
public:
    Commander(std::string FileName, float x, float y);
};

#endif // COMMANDER_H
