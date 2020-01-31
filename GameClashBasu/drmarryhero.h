#ifndef DRMARRYHERO_H
#define DRMARRYHERO_H
#include "heroabstractclass.h"

class DrmarryHero : public HeroAbstractClass
{
private:

public:
    DrmarryHero(std::string FileName, float x, float y);
    void setAttribute();
    void attack();
};

#endif // DRMARRYHERO_H
