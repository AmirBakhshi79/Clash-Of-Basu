#include "state.h"

State::State(sf::RenderWindow* window , std::map<std::string, int>* SupportedKeys, std::stack<State*>* states)
{
    this->SupportedKeys = SupportedKeys;
    this->window = window;
    this->states = states;
    this->quit = false;
}
State::~State()
{

}
const bool& State::getQuit() const
{
    return this->quit;
}
void State::updateMousePosition()
{
    this->MousePositionScreen = sf::Mouse::getPosition();
    this->MousePositionWindow = sf::Mouse::getPosition();
    this->MousePositionView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}

void State::endState()
{
    this->quit = true;

}
