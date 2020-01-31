#include "commanderhero.h"

CommanderHero::CommanderHero(std::string FileName, float x, float y) : HeroAbstractClass(FileName, x, y)
{
    this->setAttribute();
}

void CommanderHero::setAttribute()
{
    this->Power = 3;
    this->Health = 7;
    this->Ability = true;

}

void CommanderHero::attack()
{

}
