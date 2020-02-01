#ifndef TILE_H
#define TILE_H
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <map>
#include <stack>


enum TileColor {TL_COLORI = 0, TL_COLORII, TL_COLORIII};

class Tile
{
private:
    sf::Texture texture;
    sf::Color Colori = sf::Color::White;
    sf::Color Colorii = sf::Color::Red;
    sf::Color Coloriii = sf::Color::Blue;
public:
    int y;
    Tile();
    sf::Sprite sprite;
    TileColor gridColor;
    const bool isColoriii();
    void updateTexture(sf::Texture& t);
    void updateTilesIcons(sf::Vector2f& MousePosition);
    void setPosition(float x, float y);
    void setTexture(sf::Texture& Temp);
    void render(sf::RenderTarget* target);
    int getIdentifyNum();

    void setColor(sf::Color Color);
};

#endif // TILE_H
