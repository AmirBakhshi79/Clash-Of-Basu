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
    sf::Texture Icon;
    sf::Sprite Hero;
public:
    virtual ~HeroAbstractClass();
    HeroAbstractClass(std::string FileName, float x, float y);

    int getHealth();
    int getPower();
    void setTexture(std::string FileName);
    virtual void setAttribute() = 0;

    virtual void attack() = 0;
    virtual void update(const float& dt);
    virtual void render(sf::RenderTarget* target);
    bool isDead();



};

#endif // HEROABSTRACTCLASS_H
