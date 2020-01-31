#include "leonhero.h"

LeonHero::LeonHero(std::string FileName, float x, float y) : HeroAbstractClass(FileName, x, y)
{
    this->setAttribute();
}

void LeonHero::setAttribute()
{
    this->Power = 3;
    this->Health = 10;
    this->Ability = true;
}

void LeonHero::attack()
{

}
