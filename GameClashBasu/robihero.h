#ifndef ROBIHERO_H
#define ROBIHERO_H

#include "heroabstractclass.h"
class ROBIHero : public HeroAbstractClass
{
private:

public:
    ROBIHero(std::string FileName, float x, float y);
    void setAttribute();
    void attack();
};

#endif // ROBIHERO_H
