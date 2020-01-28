#include "gianthero.h"

void GiantHero::setAttribute()
{
    this->Power = 20;
    this->Health = 4;
    this->Ability = true;

}

GiantHero::GiantHero()
{
    this->setAttribute();
}
