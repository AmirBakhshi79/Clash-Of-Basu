#include "professorhero.h"

ProfessorHero::ProfessorHero(std::string FileName, float x, float y) : HeroAbstractClass(FileName, x, y)
{
    this->setAttribute();
    this->NameHero = Name::Professor;
}

void ProfessorHero::setAttribute()
{
    this->Power = 3;
    this->Health = 11;
    this->Ability = true;
}

void ProfessorHero::attack(HeroAbstractClass* hero, int x)
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
