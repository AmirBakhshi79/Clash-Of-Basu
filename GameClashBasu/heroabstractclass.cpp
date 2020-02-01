#include "heroabstractclass.h"

HeroAbstractClass::HeroAbstractClass(std::string FileName, float x, float y)
{
    this->Hero.setPosition(x, y);
    this->setTexture(FileName);
}

int HeroAbstractClass::getPower()
{
    return this->Power;

}

void HeroAbstractClass::Damage(int x)
{
    this->Health = this->Health - x;

}

void HeroAbstractClass::setTexture(std::string FileName)
{
    const char* FN = FileName.c_str();
    this->Icon.loadFromFile(FN);
    this->Hero.setTexture(this->Icon);
    this->Hero.setScale(1.2f, 1.2f);
}


void HeroAbstractClass::update(const float &dt)
{

}

void HeroAbstractClass::render(sf::RenderTarget *target)
{
    target->draw(this->Hero);
}

bool HeroAbstractClass::isDead()
{
    if (this->Health <= 0)
        return true;
    return false;

}
HeroAbstractClass::~HeroAbstractClass()
{

}

int HeroAbstractClass::getHealth()
{
    return this->Health;
}
