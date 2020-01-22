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


}
void Entity::setTexture(std::string FileName)
{
    const char* FN = FileName.c_str();
    this->texture.loadFromFile(FN);
    this->sprite.setTexture(this->texture);
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
