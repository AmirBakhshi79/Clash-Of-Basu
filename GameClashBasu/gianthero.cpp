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
    this->NameHero == Name::Giant;
}

void GiantHero::attack(HeroAbstractClass* hero, int x)
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
