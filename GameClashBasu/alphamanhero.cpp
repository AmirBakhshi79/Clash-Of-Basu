#include "alphamanhero.h"

AlphaManHero::AlphaManHero(std::string FileName, float x, float y ) : HeroAbstractClass(FileName, x, y)
{
    this->setAttribute();
    this->NameHero = Name::Alphaman;
}

void AlphaManHero::setAttribute()
{
    this->Power = 2;
    this->Health = 13;
    this->Ability = true;

}

void AlphaManHero::attack(HeroAbstractClass* hero, int x)
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
