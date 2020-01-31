#include "professorhero.h"

ProfessorHero::ProfessorHero(std::string FileName, float x, float y) : HeroAbstractClass(FileName, x, y)
{
    this->setAttribute();
}

void ProfessorHero::setAttribute()
{
    this->Power = 3;
    this->Health = 11;
    this->Ability = true;
}

void ProfessorHero::attack()
{

}
