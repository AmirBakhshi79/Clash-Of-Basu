#ifndef KRATOSHERO_H
#define KRATOSHERO_H

#include "heroabstractclass.h"
class KratosHero : public HeroAbstractClass
{
private:

public:
    KratosHero(std::string FileName, float x, float y);
    void setAttribute();
    void attack(HeroAbstractClass* , int);
};

#endif // KRATOSHERO_H
