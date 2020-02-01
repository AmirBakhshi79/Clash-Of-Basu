#ifndef HEROABSTRACTCLASS_H
#define HEROABSTRACTCLASS_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

enum class Name {Giant = 0, Snipper, Drmarry, Commander, Mrsghost, Kratos, Robi, Leon, Alphaman, Professor};

class HeroAbstractClass
{
private:
protected:
    int Power;
    int Health;
    bool Ability;
    sf::Texture Icon;


public:
    virtual ~HeroAbstractClass();
    HeroAbstractClass(std::string FileName, float x, float y);
    sf::Sprite Hero;
    int getHealth();
    int getPower();
    bool Hideness = true;
    Name NameHero;
    virtual void Damage(int x);
    void setTexture(std::string FileName);
    virtual void setAttribute() = 0;

    virtual void attack(HeroAbstractClass* , int) = 0;
    virtual void update(const float& dt);
    virtual void render(sf::RenderTarget* target);
    bool isDead();



};

#endif // HEROABSTRACTCLASS_H
