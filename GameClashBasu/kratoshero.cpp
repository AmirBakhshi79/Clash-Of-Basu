#include "kratoshero.h"

KratosHero::KratosHero(std::string FileName, float x, float y) : HeroAbstractClass(FileName, x, y)
{
    this->setAttribute();
    this->NameHero = Name::Kratos;
}

void KratosHero::setAttribute()
{
    this->Power = 3;
    this->Health = 15;
    this->Ability = true;
}

void KratosHero::attack(HeroAbstractClass* hero, int x)
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
