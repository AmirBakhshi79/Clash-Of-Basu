#include "snipperhero.h"

SnipperHero::SnipperHero(std::string FileName, float x, float y) : HeroAbstractClass(FileName, x, y)
{
    this->setAttribute();
}

void SnipperHero::setAttribute()
{
    this->Power = 4;
    this->Health = 9;
    this->Ability = true;
}

void SnipperHero::attack()
{

}
