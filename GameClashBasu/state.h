#ifndef STATE_H
#define STATE_H
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <map>
#include <stack>
class State
{
private:
    std::vector<sf::Texture> textures;
    sf::RenderWindow* window;
    bool quit;
protected:
public:
    void checkForQuit();
    virtual void endState() = 0;
    const bool& getQuit() const;
    State(sf::RenderWindow* window);
    virtual ~State();
    virtual void updateKeybindes(const float& dt) = 0;
    virtual void update(const float& dt) = 0;
    virtual void render(sf::RenderTarget* target = NULL) = 0;
};

#endif // STATE_H
