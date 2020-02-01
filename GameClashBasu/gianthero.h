#ifndef GIANTHERO_H
#define GIANTHERO_H
#include "heroabstractclass.h"

class GiantHero : public HeroAbstractClass
{
private:

public:
    void setAttribute();
    GiantHero(std::string FileName, float x, float y);
    void attack(HeroAbstractClass* , int);
};

#endif // GIANTHERO_H
