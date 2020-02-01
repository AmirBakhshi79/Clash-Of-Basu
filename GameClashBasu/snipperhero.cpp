#include "snipperhero.h"

SnipperHero::SnipperHero(std::string FileName, float x, float y) : HeroAbstractClass(FileName, x, y)
{
    this->setAttribute();
    this->NameHero = Name::Snipper;
}

void SnipperHero::setAttribute()
{
    this->Power = 4;
    this->Health = 9;
    this->Ability = true;
}

void SnipperHero::attack(HeroAbstractClass* hero , int x)
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
