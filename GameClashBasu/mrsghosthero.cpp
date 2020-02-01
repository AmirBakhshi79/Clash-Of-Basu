#include "mrsghosthero.h"

MrsGhostHero::MrsGhostHero(std::string FileName, float x, float y) : HeroAbstractClass(FileName, x, y)
{
    this->setAttribute();
    this->NameHero = Name::Mrsghost;
}

void MrsGhostHero::setAttribute()
{
    this->Power = 3;
    this->Health = 15;
    this->Ability = true;

}

void MrsGhostHero::attack(HeroAbstractClass* hero, int x)
{
    hero->Damage(this->Power);
    hero->Hideness = false;
    if (hero->NameHero == Name::Leon)
    {
        this->Health = this->Health - 2;
    }
    if (hero->NameHero == Name::Professor)
    {
        this->Hideness = false;
    }

}

void MrsGhostHero::Damage()
{

}
