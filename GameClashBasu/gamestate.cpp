#include "gamestate.h"

GameState::GameState(sf::RenderWindow* window , std::map<std::string, int>* SupportedKeys, std::stack<State*>* states)
    : State(window , SupportedKeys , states)
{
    ::x = 1400;
    initEntities();
    initTiles();
}
void GameState::render(sf::RenderTarget* target)
{
    //this->player.render(target);
    for (auto &item : this->Entities)
    {
        item->render(target);
    }
    for (auto &item1 : this->Tiles1)
    {
        for (auto &item2 :item1)
        {
            item2.render(target);
        }
    }
    /*
    for (int i = 0; i < 9; i++)
    {
        for(int j = 0, y = 20; j < 9, y <= 180; j++, y = y + 20)
        {
            this->Tiles1[i][j].render(target);
        }
    }
    */

}
void GameState::update(const float& dt)
{
    this->updateInput(dt);
    this->updateMousePosition();
    this->updateIcons();
    this->updateTileIcons();
    //this->selectWitchIcon();
    //this->player.update(dt);
}

GameState::~GameState()
{
    for (size_t i = 0; i < Entities.size(); i++)
    {
        delete Entities.at(i);
        Entities.erase(Entities.begin() + i);
    }
   // std::cout<< static_cast <float>(this->Tiles[0][0].sprite.getScale()) << std::endl;
    //std::cout << this->Entities.size() << std::endl;

    //std::cout << this->Entities.at(0)<< std::endl;
}

void GameState::updateIcons()
{
    for (auto &item : this->Entities)
    {
        item->updateIcons(this->MousePositionView);

    }
}

void GameState::initTiles()
{
    unsigned short int y = 550;
    for (auto &item1 : this->Tiles1)
    {
        for (auto &item2 : item1)
        {
            item2.setPosition(::x,y);
            y = y + 51;
        }
        ::x = ::x + 51;
        y = 550;
    }
    /*
    for (unsigned short int i = 0; i < 9; i++)
    {
        for(unsigned short int j = 0, y = 550; j < 9, y <= 1009; j++, y = y + 51)
        {
            this->Tiles1.at()
            //this->Tiles1[i][j].setPosition(::x , y);
            ::x = ::x + 5.2;
        }
    }
    */
}

void GameState::updateTileIcons()
{
    for (auto &item1 : this->Tiles1)
    {
        for (auto &item2 : item1)
        {
            item2.updateTilesIcons(this->MousePositionView);
        }
    }
}
/*
void GameState::selectWitchIcon()
{
    for (auto &item1 : this->Entities)
    {
        if (item1->IconColor == ICN_COLORIII)
        {
            std::cout << "Clicked" << std::endl;
            sf::Texture temp;
            switch(item1->WitchTexture )
            {
            case GIANT:
                temp.loadFromFile("../Images/giant.png");
                std::cout << "Giant is loaded" << std::endl;
                break;

            }
            this->setIconOnGird(temp);
            /*
            for (auto &item2 : this->Tiles1)
            {
                for (auto &item3 : item2)
                {
                    item3.updateTilesIcons(this->MousePositionView);
                    std::cout << "Im Here" << std::endl;
                    if (item3.isColoriii())
                    {
                        std::cout << "Im Here" << std::endl;
                        item3.updateTexture(temp);
                    }
                }
            }

        }
    }
}

void GameState::setIconOnGird(sf::Texture &t)
{
    for (auto &item1 : this->Tiles1)
    {
        for (auto &item2 : item1)
        {

            this->updateIcons();
            /*
            std::cout << "A" << std::endl;
            std::cout << item2.TileColor;

            if (item2.gridColor == TL_COLORIII)
            {
                std::cout << "A" << std::endl;
                item2.updateTexture(t);
                this->updateIcons();
            }
            //this->updateIcons();
        }
        this->updateIcons();
    }
    this->updateIcons();
}
*/
void GameState::updateInput(const float &dt)
{

    /*
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        this->player.move(dt, -1.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        this->player.move(dt, 1.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        this->player.move(dt, 0.f, -1.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        this->player.move(dt, 0.f, 1.f);
    */
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        this->endState();
}

void GameState::initEntities()
{
    this->Entities.push_back(new Giant("../Images/giant.png", 10, 10));
}
