#ifndef ALPHAMANHERO_H
#define ALPHAMANHERO_H
#include "heroabstractclass.h"

class AlphaManHero : public HeroAbstractClass
{
private:

public:
    AlphaManHero(std::string FileName, float x, float y);
    void setAttribute();
    void attack(HeroAbstractClass* , int);
};

#endif // ALPHAMANHERO_H
