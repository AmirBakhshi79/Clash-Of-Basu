#include "game.h"

Game::Game()
{
    this->initWindow();
    this->initStates();
}
Game::~Game()
{
    delete this->window;
    while (!this->States.empty())
    {
        delete this->States.top();
        this->States.pop();
    }
}
void Game::initWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(512,512) , "C++ Game");
}
void Game::update()
{
    this->updateSFMLEvents();

    if (!this->States.empty())
    {
        this->States.top()->update(this->dt);
        if (this->States.top()->getQuit())
        {
            this->States.top()->endState();
            delete this->States.top();
            this->States.pop();
        }
    }
    else
    {
        this->window->close();
    }
}
void Game::render()
{
    this->window->clear();
    if (!this->States.empty())
    {
        this->States.top()->render(this->window);
    }
    this->window->display();
}
void Game::updateSFMLEvents()
{
    while (this->window->pollEvent(this->event))
    {
        if (this->event.type == sf::Event::Closed)
        {
            this->window->close();
        }
    }
}
void Game::run()
{
    while(this->window->isOpen())
    {
        this->updateDT();
        this->update();
        this->render();
    }
}
void Game::updateDT()
{
    this->dt = this->dtClock.restart().asSeconds();
    /*update dt variable time take time for update and render*/
    //std::cout << this->dt ;
}
void Game::initStates()
{
    this->States.push(new GameState(this->window));
}
