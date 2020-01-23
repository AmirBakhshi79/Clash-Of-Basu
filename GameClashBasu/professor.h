#ifndef PROFESSOR_H
#define PROFESSOR_H
#include "entity.h"

class Professor : public Entity
{
public:
    Professor(std::string FileName, float x, float y);
};

#endif // PROFESSOR_H
