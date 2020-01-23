#ifndef HEROABSTRACTCLASS_H
#define HEROABSTRACTCLASS_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>


class HeroAbstractClass
{
private:
protected:
    int Power;
    int Health;
    bool Ability;
public:
    virtual ~HeroAbstractClass();
    HeroAbstractClass();
    virtual void setPower() = 0;
    virtual void setHealth() = 0;
    virtual void update(const float& dt);
    virtual void render(sf::RenderTarget* target);
};

#endif // HEROABSTRACTCLASS_H
