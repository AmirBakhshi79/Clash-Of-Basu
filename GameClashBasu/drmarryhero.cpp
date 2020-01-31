#include "drmarryhero.h"

DrmarryHero::DrmarryHero(std::string FileName, float x, float y) : HeroAbstractClass(FileName, x, y)
{
    this->setAttribute();
}

void DrmarryHero::setAttribute()
{
    this->Power = 2;
    this->Health = 8;
    this->Ability = true;
}

void DrmarryHero::attack()
{

}
