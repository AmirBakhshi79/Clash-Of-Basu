#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "state.h"
static float x;
static float m;
class GameState : public State
{
private:
    //Entity player;
    std::vector<Entity*> Entities;
    std::array<std::array<Tile, 9>, 9> Tiles1;
    std::array<std::array<Tile, 9>, 9> Tiles2;


public:
    bool Statu1 = true;
    unsigned short int x = 0;




    void updateInput(const float& dt);
    void initEntities();
    GameState(sf::RenderWindow* window ,std::map<std::string, int>* SupportedKeys, std::stack<State*>* states);
    ~GameState();
    void updateIcons();
    void initTiles();
    void updateTileIcons();

    void selectHero();
    void selectGrid(sf::Texture temp);
    virtual void update(const float& dt);
    virtual void render(sf::RenderTarget* target = NULL);


};

#endif // GAMESTATE_H
