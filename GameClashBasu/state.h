#ifndef STATE_H
#define STATE_H
#include "giant.h"
#include "snipper.h"
#include "drmarry.h"
#include "commander.h"
#include "mrsghost.h"
#include "professor.h"
#include "kratos.h"
#include "leon.h"
#include "robi.h"
#include "alphaman.h"
class State
{
private:

protected:
    std::stack<State*>* states;
    std::vector<sf::Texture> textures;
    sf::RenderWindow* window;
    bool quit;
    std::map<std::string, int> * SupportedKeys;
    sf::Vector2i MousePositionScreen;
    sf::Vector2i MousePositionWindow;
    sf::Vector2f MousePositionView;
public:
    const bool& getQuit() const;
    State(sf::RenderWindow* window , std::map<std::string, int>* SupportedKeys, std::stack<State*>* states);
    virtual ~State();
    void endState();
    virtual void updateMousePosition();
    virtual void updateInput(const float& dt) = 0;
    virtual void update(const float& dt) = 0;
    virtual void render(sf::RenderTarget* target = NULL) = 0;
};

#endif // STATE_H
