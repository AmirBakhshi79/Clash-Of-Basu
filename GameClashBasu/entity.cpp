#include "entity.h"
/*
Entity::Entity()
{
    this->Shape.setSize(sf::Vector2f(50.f,50.f));
    this->Shape.setFillColor(sf::Color::White);
    this->movementSpeed = 100.f;
}

void Entity::update(const float &dt)
{

}
void Entity::render(sf::RenderTarget* target)
{
    target->draw(this->Shape);
}
void Entity::move(const float &dt, float x, float y)
{
    this->Shape.move(x * this->movementSpeed * dt, y * this->movementSpeed * dt);
}
Entity::~Entity()
{

}
*/
Entity::Entity(std::string FileName, float x, float y)
{
    this->setPositionSprite(x , y);
    this->setTexture(FileName);
    this->Colori = sf::Color::White;
    this->Colorii = sf::Color::Red;
    this->Coloriii = sf::Color::Black;
    this->IconColor = ICN_COLORI;


}
void Entity::setTexture(std::string FileName)
{
    const char* FN = FileName.c_str();
    this->texture.loadFromFile(FN);
    this->sprite.setTexture(this->texture);
    this->sprite.setColor(sf::Color::Blue);
    this->sprite.setScale(1.3f,1.3f);
}

void Entity::updateIcons(sf::Vector2f &MousePosition)
{
    this->IconColor = ICN_COLORI;
    if (this->sprite.getGlobalBounds().contains(MousePosition))
    {
       this->IconColor = ICN_COLORII;
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            this->IconColor = ICN_COLORIII;
        }
    }
    switch (this->IconColor) {
    case ICN_COLORI:
        this->sprite.setColor(this->Colori);
        break;
    case ICN_COLORII:
        this->sprite.setColor(this->Colorii);
        break;
    case ICN_COLORIII:
        this->sprite.setColor(this->Coloriii);
        break;
    default:
        this->sprite.setColor(this->Colori);
        break;
    }

}
void Entity::render(sf::RenderTarget *target)
{
    target->draw(this->sprite);
}
void Entity::update(const float &dt)
{

}
void Entity::setPositionSprite(float x, float y)
{
    this->sprite.setPosition(x , y);
}
Entity::~Entity()
{

}

const bool Entity::iconIsPressed() const
{
    if (this->IconColor == ICN_COLORIII)
        return true;
    return false;
}
