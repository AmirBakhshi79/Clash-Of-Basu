#include "gianthero.h"

void GiantHero::setAttribute()
{
    this->Power = 20;
    this->Health = 4;
    this->Ability = true;

}

GiantHero::GiantHero(std::string FileName, float x, float y) : HeroAbstractClass(FileName, x, y)
{
    this->setAttribute();
}

void GiantHero::attack()
{

}
