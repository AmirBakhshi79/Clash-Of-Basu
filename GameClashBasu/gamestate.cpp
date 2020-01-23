#include "gamestate.h"

GameState::GameState(sf::RenderWindow* window , std::map<std::string, int>* SupportedKeys, std::stack<State*>* states)
    : State(window , SupportedKeys , states)
{
    ::x = 1460;
    ::m = 0;
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
    for (auto &item1 : this->Tiles2)
    {
        for (auto &item2 : item1)
        {
            item2.render(target);
        }
    }

}
void GameState::update(const float& dt)
{
    this->updateInput(dt);
    this->updateMousePosition();
    this->updateIcons();
    this->updateTileIcons();
    sf::Event event;





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
    for (short int i = 0; i < this->Entities.size(); i++)
    {
        if (this->Entities.at(i)->sprite.getGlobalBounds().contains(this->MousePositionView))
        {
            this->Entities.at(i)->setColor(sf::Color::Red);
            //std::cout << this->Entities.at(0)->W << " " << this->Entities.at(1)->W << std::endl;
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                this->Entities.at(i)->setColor(sf::Color::Blue);
                for (short int j = 0;j < this->Entities.size(); j++)
                {
                    if (this->Entities.at(j)->W != this->Entities.at(i)->W)
                    {
                        this->Entities.at(j)->setColor(sf::Color::White);
                    }
                }
            }
            for (short int j = 0;j < this->Entities.size(); j++)
            {

                if (this->Entities.at(j)->W != this->Entities.at(i)->W)
                {

                    this->Entities.at(j)->setColor(sf::Color::White);
                }
            }

        }
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
    y = 550;
    for (auto &item1 : this->Tiles2)
    {
        for (auto &item2 : item1)
        {
            item2.setPosition(::m,y);
            y = y + 51;
        }
        ::m = ::m + 51;
        y = 550;
    }

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
    for (auto &item1 : this->Tiles2)
    {
        for (auto &item2 : item1)
        {
            item2.updateTilesIcons(this->MousePositionView);
        }
    }
}

void GameState::selectHero(sf::Event event)
{

}

void GameState::selectGrid(sf::Texture temp)
{
    bool status = true;
    while(status)
    {
        for (auto &item : this->Tiles1)
        {
            for (auto &item2 : item)
            {
                std::cout << "Im\n";
                if(item2.sprite.getGlobalBounds().contains(this->MousePositionView))
                {

                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {

                        item2.setTexture(temp);
                        status = false;
                    }
                }
            }
        }
    }
}


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
    this->Entities.push_back(new Giant("../Images/giant.png",0,0));
    this->Entities.push_back(new Snipper("../Images/snipper.png",100,0));
    this->Entities.push_back(new DrMarry("../Images/drmarry.png",200,0));
    this->Entities.push_back(new Commander("../Images/commander.png",300,0));
    this->Entities.push_back(new Professor("../Images/professor.png",400,0));
    this->Entities.push_back(new Robi("../Images/robi.png",500,0));
    this->Entities.push_back(new Leon("../Images/leon.png",600,0));
    this->Entities.push_back(new AlphaMan("../Images/alphaman.png",700,0));
    this->Entities.push_back(new Kratos("../Images/kratos.png",800,0));
    this->Entities.push_back(new MrsGhost("../Images/mrsghost.png",900,0));
}
