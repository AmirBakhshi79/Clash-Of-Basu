#include "gamestate.h"

GameState::GameState(sf::RenderWindow* window , std::map<std::string, int>* SupportedKeys, std::stack<State*>* states)
    : State(window , SupportedKeys , states)
{
    initEntities();
}
void GameState::render(sf::RenderTarget* target)
{
    //this->player.render(target);
    for (auto &item : this->Entities)
    {
        item->render(target);
    }
}
void GameState::update(const float& dt)
{
    this->updateInput(dt);
    this->updateMousePosition();
    //this->player.update(dt);
}

GameState::~GameState()
{
    for (size_t i = 0; i < Entities.size(); i++)
    {
        delete Entities.at(i);
        Entities.erase(Entities.begin() + i);
    }
    //std::cout << this->Entities.size() << std::endl;

    //std::cout << this->Entities.at(0)<< std::endl;
}
void GameState::updateInput(const float &dt)
{

    /*
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        this->player.move(dt, -1.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        this->player.move(dt, 1.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        this->player.move(dt, 0.f, -1.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        this->player.move(dt, 0.f, 1.f);
        */
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        this->endState();
}

void GameState::initEntities()
{
    this->Entities.push_back(new Giant("../Images/giant.png", 10, 10));
}
