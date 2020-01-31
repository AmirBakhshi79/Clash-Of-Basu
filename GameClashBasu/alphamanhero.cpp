#include "alphamanhero.h"

AlphaManHero::AlphaManHero(std::string FileName, float x, float y ) : HeroAbstractClass(FileName, x, y)
{
    this->setAttribute();
}

void AlphaManHero::setAttribute()
{
    this->Power = 2;
    this->Health = 13;
    this->Ability = true;

}

void AlphaManHero::attack()
{

}
