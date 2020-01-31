#include "kratoshero.h"

KratosHero::KratosHero(std::string FileName, float x, float y) : HeroAbstractClass(FileName, x, y)
{
    this->setAttribute();
}

void KratosHero::setAttribute()
{
    this->Power = 3;
    this->Health = 15;
    this->Ability = true;
}

void KratosHero::attack()
{

}
