#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "state.h"
class GameState : public State
{
private:

public:
    void updateKeybindes(const float& dt);
    GameState(sf::RenderWindow* window);
    ~GameState();
    virtual void endState();
    virtual void update(const float& dt);
    virtual void render(sf::RenderTarget* target = NULL);
};

#endif // GAMESTATE_H
