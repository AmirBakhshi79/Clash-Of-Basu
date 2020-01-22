#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <map>
#include <stack>
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
class Entity
{
private:
protected:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Color Colori;
    sf::Color Colorii;
    sf::Color Coloriii;
public:
    Entity(std::string FileName, float x, float y);
    ~Entity();
    void setPositionSprite(float x, float y);
    void setTexture(std::string FileName);
    void update(const float& dt);
    void render(sf::RenderTarget* target);
};
#endif // ENTITY_H
