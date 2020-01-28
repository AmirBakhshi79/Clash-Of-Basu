#include "leonhero.h"

LeonHero::LeonHero()
{
    this->setAttribute();
}

void LeonHero::setAttribute()
{
    this->Power = 3;
    this->Health = 10;
    this->Ability = true;
}
