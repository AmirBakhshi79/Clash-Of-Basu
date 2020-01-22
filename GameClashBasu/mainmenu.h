#ifndef MAINMENU_H
#define MAINMENU_H
#include "state.h"
#include "button.h"
#include "gamestate.h"
class MainMenu : public State
{
private:
    sf::RectangleShape BackGround;
    sf::Font font;
    std::map<std::string, Button*> buttons;
    void initButtons();
    sf::Texture BGtexture;
public:
    void updateButtons();
    void initBackGround();
    void renderButtons(sf::RenderTarget* target = NULL);
    void updateInput(const float& dt);
    MainMenu(sf::RenderWindow* window ,std::map<std::string, int>* SupportedKeys, std::stack<State*>* states);
    ~MainMenu();
    void initFont();
    virtual void update(const float& dt);
    virtual void render(sf::RenderTarget* target = NULL);
};

#endif // MAINMENU_H
