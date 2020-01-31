#ifndef MRSGHOSTHERO_H
#define MRSGHOSTHERO_H

#include "heroabstractclass.h"
class MrsGhostHero :public HeroAbstractClass
{
private:

public:
    MrsGhostHero(std::string FileName, float x, float y);
    void setAttribute();
    void attack();
};

#endif // MRSGHOSTHERO_H
