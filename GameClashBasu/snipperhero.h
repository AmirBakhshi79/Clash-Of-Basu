#ifndef SNIPPERHERO_H
#define SNIPPERHERO_H

#include "heroabstractclass.h"
class SnipperHero : public HeroAbstractClass
{
private:


public:
    SnipperHero(std::string FileName, float x, float y);
    void setAttribute();
    void attack();
};

#endif // SNIPPERHERO_H
