#ifndef MRSGHOSTHERO_H
#define MRSGHOSTHERO_H

#include "heroabstractclass.h"
class MrsGhostHero :public HeroAbstractClass
{
private:
    bool twice = true;
public:
    MrsGhostHero(std::string FileName, float x, float y);
    void setAttribute();
    void attack(HeroAbstractClass* , int);
    virtual void Damage();
};

#endif // MRSGHOSTHERO_H
