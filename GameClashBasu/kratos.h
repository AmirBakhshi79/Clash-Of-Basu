#ifndef KRATOS_H
#define KRATOS_H

#include "entity.h"
class Kratos : public Entity
{
public:
    Kratos(std::string FileName, float x, float y);
};

#endif // KRATOS_H
