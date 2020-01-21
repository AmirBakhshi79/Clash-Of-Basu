#include "gamestate.h"

GameState::GameState(sf::RenderWindow* window)
    : State(window)
{

}
void GameState::render(sf::RenderTarget* target)
{

}
void GameState::update(const float& dt)
{
    this->updateKeybindes(dt);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        std::cout << "A" << std::endl;
}

GameState::~GameState()
{

}
void GameState::updateKeybindes(const float &dt)
{
    this->checkForQuit();
}
void GameState::endState()
{
    std::cout << "Ending the state" << std::endl;
}
