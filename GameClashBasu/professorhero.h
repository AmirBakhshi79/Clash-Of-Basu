#ifndef PROFESSORHERO_H
#define PROFESSORHERO_H
#include "heroabstractclass.h"

class ProfessorHero : public HeroAbstractClass
{
private:

public:
    ProfessorHero(std::string FileName, float x, float y);
    void setAttribute();
    void attack();
};

#endif // PROFESSORHERO_H
