
#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "state.h"
#include "gianthero.h"

#include "snipperhero.h"
#include "mrsghosthero.h"
#include "drmarryhero.h"
#include "professorhero.h"
#include "kratoshero.h"
#include "leonhero.h"
#include "alphamanhero.h"
#include "robihero.h"
#include "commanderhero.h"



static float x;
static float m;
static float position12;
static float position22;
class GameState : public State
{
private:
    sf::RectangleShape BackGroound;
    sf::Texture BGtexture;
    //Entity player;
    std::vector<Entity*> Entities;
    std::array<std::array<Tile, 9>, 9> Tiles1;
    std::array<std::array<Tile, 9>, 9> Tiles2;

    std::vector<int> Heroes;
    std::vector<int> Heroes2;

    std::vector<HeroAbstractClass*> Entity1;
    std::vector<HeroAbstractClass*> Entity2;
    void initBackGround();

public:

    bool Status1 = true;
    bool Status2 = false;
    bool Status3 = true;

    bool Status4 = true;
    bool Status5 = false;
    unsigned short int x = 0;
    unsigned short int y = 0;
    float position11;
    float position21;



    void fixTileColor();


    void updateInput(const float& dt);
    void initEntities();
    GameState(sf::RenderWindow* window ,std::map<std::string, int>* SupportedKeys, std::stack<State*>* states);
    ~GameState();
    void updateIcons();
    void initTiles();
    void updateTileIcons();

    void selectHero();

    void selectTileForHero2();
    void selectTileForHero();


    void selectHero2();
    void selectGrid(sf::Texture temp);
    virtual void update(const float& dt);
    virtual void render(sf::RenderTarget* target = NULL);

    void updateTiles();


};

#endif // GAMESTATE_H
