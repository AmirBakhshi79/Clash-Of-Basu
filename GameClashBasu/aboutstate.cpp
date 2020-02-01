#include "aboutstate.h"

AboutState::AboutState(sf::RenderWindow* window , std::map<std::string, int>* SupportedKeys, std::stack<State*>* states) : State(window, SupportedKeys, states)
{
    this->initBackground();
}

void AboutState::update(const float &dt)
{
    this->updateInput(dt);
    this->updateMousePosition();

}

void AboutState::render(sf::RenderTarget *target)
{
    target->draw(this->Background);
}

void AboutState::updateInput(const float &dt)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        this->endState();
}

void AboutState::initBackground()
{
    this->Background.setSize(sf::Vector2f(
                                 static_cast<float>(this->window->getSize().x),
                                 static_cast<float> (this->window->getSize().y)
                                 )
                             );
    this->BGtexture.loadFromFile("../Images/FF.jpg");

    this->Background.setTexture(&this->BGtexture);

}
AboutState::~AboutState()
{

}
