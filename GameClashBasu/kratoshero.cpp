#include "kratoshero.h"

KratosHero::KratosHero()
{
    this->setAttribute();
}

void KratosHero::setAttribute()
{
    this->Power = 3;
    this->Health = 15;
    this->Ability = true;
}
