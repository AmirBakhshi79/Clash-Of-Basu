#ifndef COMMANDERHERO_H
#define COMMANDERHERO_H

#include "heroabstractclass.h"
class CommanderHero : public HeroAbstractClass
{
private:

public:
    CommanderHero(std::string FileName, float x, float y);
    void setAttribute();
    void attack();
};

#endif // COMMANDERHERO_H
