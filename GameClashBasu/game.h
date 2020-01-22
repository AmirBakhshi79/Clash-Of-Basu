#ifndef GAME_H
#define GAME_H

#include "mainmenu.h"
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
    std::map<std::string, int> SupportedKeys;
    std::stack<State*> States;
public:
    void update();
    void updateDT();
    void render();
    void initSupportedKeys();
    void run();
    void updateSFMLEvents();
    Game();
    virtual ~Game();
};

#endif // GAME_H
