#include "snipperhero.h"

SnipperHero::SnipperHero()
{
    this->setAttribute();
}

void SnipperHero::setAttribute()
{
    this->Power = 4;
    this->Health = 9;
    this->Ability = true;
}
