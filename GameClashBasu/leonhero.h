#ifndef LEONHERO_H
#define LEONHERO_H

#include "heroabstractclass.h"
class LeonHero : public HeroAbstractClass
{
private:

public:
    LeonHero(std::string FileName, float x, float y);
    void setAttribute();
    void attack(HeroAbstractClass* , int);
};

#endif // LEONHERO_H
