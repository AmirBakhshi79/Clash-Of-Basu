#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "state.h"
class GameState : public State
{
private:
    //Entity player;
    std::vector<Entity*> Entities;
public:
    void updateInput(const float& dt);
    void initEntities();
    GameState(sf::RenderWindow* window ,std::map<std::string, int>* SupportedKeys, std::stack<State*>* states);
    ~GameState();
    virtual void update(const float& dt);
    virtual void render(sf::RenderTarget* target = NULL);
};

#endif // GAMESTATE_H
