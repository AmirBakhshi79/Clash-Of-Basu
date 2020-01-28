#include "robihero.h"

ROBIHero::ROBIHero()
{
    this->setAttribute();
}

void ROBIHero::setAttribute()
{
    this->Power = 2;
    this->Health = 12;
    this->Ability = true;
}
