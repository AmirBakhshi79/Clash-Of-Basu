#include "robihero.h"

ROBIHero::ROBIHero(std::string FileName, float x, float y) : HeroAbstractClass(FileName, x, y)
{
    this->setAttribute();
}

void ROBIHero::setAttribute()
{
    this->Power = 2;
    this->Health = 12;
    this->Ability = true;
}

void ROBIHero::attack()
{

}
