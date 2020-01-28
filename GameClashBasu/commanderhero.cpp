#include "commanderhero.h"

CommanderHero::CommanderHero()
{
    this->setAttribute();
}

void CommanderHero::setAttribute()
{
    this->Power = 3;
    this->Health = 7;
    this->Ability = true;

}
