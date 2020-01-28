#include "tile.h"


Tile::Tile()
{


    this->texture.loadFromFile("../Images/Green.png");
    this->sprite.setTexture(this->texture);
    this->sprite.setScale(0.1f,0.1f);
    this->sprite.setColor(sf::Color::White);
    this->gridColor = TL_COLORI;

}

const bool Tile::isColoriii()
{
    if(this->gridColor == TL_COLORIII)
        return true;
    return false;
}

void Tile::updateTexture(sf::Texture &t)
{
    this->sprite.setTexture(t);
}


/*
void Tile::updateTilesIcons(sf::Vector2f& MousePosition)
{
    this->gridColor = TL_COLORI;
    if (this->sprite.getGlobalBounds().contains(MousePosition))
    {
        this->gridColor = TL_COLORII;
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            this->gridColor = TL_COLORIII;
            //std::cout << " Hello \n";
        }
    }
    switch (this->gridColor) {
    case TL_COLORI:
        this->sprite.setColor(this->Colori);
        break;
    case TL_COLORII:
        this->sprite.setColor(this->Colorii);
        break;
    case TL_COLORIII:
        this->sprite.setColor(this->Coloriii);
        break;
    default:
        this->sprite.setColor(this->Colori);
        break;
    }
}
*/
void Tile::setPosition(float x, float y)
{
    this->sprite.setPosition(x , y);
}

void Tile::setTexture(sf::Texture &Temp)
{
    this->sprite.setTexture(Temp);
}

void Tile::render(sf::RenderTarget *target)
{
    target->draw(this->sprite);
}

void Tile::setColor(sf::Color Color)
{
    this->sprite.setColor(Color);
}
