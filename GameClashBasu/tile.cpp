#include "tile.h"

Tile::Tile(sf::Texture texture,float x, float y)
{
    this->FillOrEmpty = false;
    this->setPosition(x , y);
    this->sprite.setTexture(texture);
    this->sprite.setColor(sf::Color::White);
}
void Tile::setPosition(float x, float y)
{
    this->sprite.setPosition(x , y);
}
void Tile::render(sf::RenderTarget *target)
{
    target->draw(this->sprite);
}


