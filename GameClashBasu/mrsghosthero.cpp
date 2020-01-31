#include "mrsghosthero.h"

MrsGhostHero::MrsGhostHero(std::string FileName, float x, float y) : HeroAbstractClass(FileName, x, y)
{
    this->setAttribute();
}

void MrsGhostHero::setAttribute()
{
    this->Power = 3;
    this->Health = 15;
    this->Ability = true;

}

void MrsGhostHero::attack()
{

}
