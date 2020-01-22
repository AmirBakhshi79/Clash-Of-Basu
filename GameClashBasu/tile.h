#ifndef TILE_H
#define TILE_H
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <map>
#include <stack>

class Tile
{
private:
    sf::Texture texture;
    sf::Sprite sprite;
    bool FillOrEmpty;


public:
    Tile(sf::Texture texture, float x, float y);
    void setPosition(float x, float y);
    void update();
    void render(sf::RenderTarget* target);
    void setTexture(sf::Texture texture);
};

#endif // TILE_H
