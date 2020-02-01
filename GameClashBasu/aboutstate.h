#ifndef ABOUTSTATE_H
#define ABOUTSTATE_H

#include "game.h"
#include "gamestate.h"
class AboutState : public State
{

private:
    sf::RectangleShape Background;
    sf::Texture BGtexture;
    std::vector <Entity*> Icons;
    sf::Font font;
    std::map<std::string, Button*> buttons;
public:
    AboutState(sf::RenderWindow* window , std::map<std::string, int>* SupportedKeys, std::stack<State*>* states);
    ~AboutState();
    virtual void update(const float& dt);
    virtual void render(sf::RenderTarget* target = NULL);
    virtual void updateInput(const float& dt) ;
    void initBackground();
    void initFont();
    void initButtons();
};

#endif // ABOUTSTATE_H
