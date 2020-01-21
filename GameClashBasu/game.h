#ifndef GAME_H
#define GAME_H

#include "gamestate.h"
class Game
{
private:
    sf::RenderWindow * window;
    sf::Event event;
    float dt;
    sf::Clock dtClock;
    void initWindow();
    void initStates();
    std::stack<State*> States;
public:
    void update();
    void updateDT();
    void render();
    void run();
    void updateSFMLEvents();
    Game();
    virtual ~Game();
};

#endif // GAME_H
