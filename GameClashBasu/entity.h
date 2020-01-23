#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <map>
#include <stack>
#include "tile.h"
/*
class Entity
{
private:
    sf::RectangleShape Shape;
    float movementSpeed;

protected:
public:
    Entity();
    ~Entity();
    void move(const float& dt, float x, float y);
    void render(sf::RenderTarget* target);
    void update(const float& dt);
};
*/
enum IconColor{ICN_COLORI = 0, ICN_COLORII, ICN_COLORIII};
enum WitchTexture{GIANT = 0, SNIPPER, DRMARRY, COMMANDER, MRSGHOST, KRATOS, ROBI, LEON, ALPHAMAN, PROFESSOR};
class Entity
{
private:
protected:
    sf::Texture texture;
    sf::Color Colori;
    sf::Color Colorii;
    sf::Color Coloriii;
public:
    Entity(std::string FileName, float x, float y);
    ~Entity();
    sf::Sprite sprite;
    const bool iconIsPressed() const;
    unsigned short IconColor;
    WitchTexture W;
    void setPositionSprite(float x, float y);
    void setTexture(std::string FileName);
    void updateIcons(sf::Vector2f& MousePosition);
    void update(const float& dt);
    void render(sf::RenderTarget* target);
    void setColor(sf::Color Color);


};
#endif // ENTITY_H
