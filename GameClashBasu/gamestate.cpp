#include "gamestate.h"

GameState::GameState(sf::RenderWindow* window , std::map<std::string, int>* SupportedKeys, std::stack<State*>* states)
    : State(window , SupportedKeys , states)
{
    ::x = 1460;
    ::m = 0;
    this->initEntities();
    this->initTiles();

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
    if (this->Status1)
    {
        this->selectHero();
    }
    if (this->Status2)
    {
        this->selectTileForHero();
    }




    //this->selectWitchIcon();
    //this->player.update(dt);
}

GameState::~GameState()
{
    for (unsigned short int i = 0; i < Entities.size(); i++)
    {
        delete Entities.at(i);
        Entities.erase(Entities.begin() + i);
    }
   // std::cout<< static_cast <float>(this->Tiles[0][0].sprite.getScale()) << std::endl;
    //std::cout << this->Entities.size() << std::endl;

    //std::cout << this->Entities.at(0)<< std::endl;
}

void GameState::updateTileIcons()
{

    for (auto &item : this->Tiles1)
    {
        for (auto &item2 : item)
        {
            if (item2.sprite.getGlobalBounds().contains(this->MousePositionView))
            {
                item2.setColor(sf::Color::Red);
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    item2.setColor(sf::Color::Blue);
                    for (auto &i : this->Tiles1)
                    {
                        for (auto &j : i)
                        {
                            if (j.y != item2.y)
                            {
                                j.setColor(sf::Color::White);
                            }
                        }
                    }
                }
                for (auto &m : this->Tiles1)
                {
                    for (auto &n : m)
                    {
                        if (n.y != item2.y)
                        {
                            n.setColor(sf::Color::White);
                        }
                    }
                }

            }
        }
    }


}
void GameState::updateIcons()
{
    for (unsigned short int i = 0; i < this->Entities.size(); i++)
    {
        if (this->Entities.at(i)->sprite.getGlobalBounds().contains(this->MousePositionView))
        {
            this->Entities.at(i)->setColor(sf::Color::Red);
            //std::cout << this->Entities.at(0)->W << " " << this->Entities.at(1)->W << std::endl;
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {

                this->Entities.at(i)->setColor(sf::Color::Blue);
                for (unsigned short int j = 0;j < this->Entities.size(); j++)
                {
                    if (this->Entities.at(j)->W != this->Entities.at(i)->W)
                    {
                        this->Entities.at(j)->setColor(sf::Color::White);
                    }
                }
            }
            for (unsigned short int j = 0;j < this->Entities.size(); j++)
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
    static short int identifyNum = 1;
    unsigned short int y = 550;
    for (auto &item1 : this->Tiles1)
    {
        for (auto &item2 : item1)
        {
            item2.setPosition(::x,y);
            y = y + 51;
            item2.y = identifyNum;
            identifyNum++;
            //std::cout << item2.y << std::endl;
            //std::cout << item2.y << std::endl;
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
/*
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
*/
void GameState::selectHero()
{

    sf::Event event;
    while (this->window->pollEvent(event) && x != 5)
    {


        for (auto &item : this->Entities)
        {
            if (item->sprite.getGlobalBounds().contains(this->MousePositionView))
            {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    switch (item->W) {
                    case GIANT:
                        this->Heroes.push_back(1);
                        std::cout << "GIANT  "<<this->Heroes.size()<<"\n";
                        break;
                    case SNIPPER:
                        this->Heroes.push_back(2);
                        std::cout << "SNIPPER  "<<this->Heroes.size()<<"\n";
                        break;
                    case DRMARRY:
                        this->Heroes.push_back(3);
                        std::cout << "DRMARRY  "<<this->Heroes.size()<<"\n";
                        break;
                    case KRATOS:
                        this->Heroes.push_back(4);
                        std::cout << "KRATOS  "<<this->Heroes.size()<<"\n";
                        break;
                    case ALPHAMAN:
                        this->Heroes.push_back(5);
                        std::cout << "ALPHAMAN  "<<this->Heroes.size()<<"\n";
                        break;
                    case LEON:
                        this->Heroes.push_back(6);
                        std::cout << "LEON  "<<this->Heroes.size()<<"\n";
                        break;
                    case COMMANDER:
                        this->Heroes.push_back(7);
                        std::cout << "COMMADNER  "<<this->Heroes.size()<<"\n";
                        break;
                    case ROBI:
                        this->Heroes.push_back(8);
                        std::cout << "ROBI  "<<this->Heroes.size()<<"\n";
                        break;
                    case MRSGHOST:
                        this->Heroes.push_back(9);
                        std::cout << "MRSGHOST  "<<this->Heroes.size()<<"\n";
                        break;
                    case PROFESSOR:
                        this->Heroes.push_back(10);
                        std::cout << "PROFESSOR  "<<this->Heroes.size()<<"\n";
                        break;

                    default:
                        break;
                    }
                    if (this->Heroes.size() == 5)
                    {
                        this->Status1 = false;
                        this->Status2 = true;
                        this->Status3 = false;
                        break;
                    }
                }
            }
        }
    }

}

void GameState::selectTileForHero()
{
    sf::Event event;
    static unsigned short int i = 0;
    //std::cout << "Enter\n";
    while (this->window->pollEvent(event) && this->y != 5)
    {

        for (auto &item1 : this->Tiles1)
        {
            for (auto &item2 : item1)
            {
                if (item2.sprite.getGlobalBounds().contains(this->MousePositionView))
                {
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {


                        sf::Texture temp;
                        switch (this->Heroes.at(i)) {
                        case 1:
                            temp.loadFromFile("../Images/giant.png");
                            item2.sprite.setTexture(temp);
                            i++;
                            std::cout << i << "\n";
                            break;
                        case 2:
                            temp.loadFromFile("../Images/snipper.png");
                            item2.sprite.setTexture(temp);
                            i++;
                            std::cout << i << "\n";
                            break;
                        case 3:
                            temp.loadFromFile("../Images/drmarry.png");
                            item2.sprite.setTexture(temp);
                            i++;
                            std::cout << i << "\n";
                            break;
                        case 4:
                            temp.loadFromFile("../Images/kratos.png");
                            item2.sprite.setTexture(temp);
                            i++;
                            std::cout << i << "\n";
                            break;
                        case 5:
                            temp.loadFromFile("../Images/alphaman.png");
                            item2.sprite.setTexture(temp);
                            i++;
                            std::cout << i << "\n";
                            break;
                        case 6:
                            temp.loadFromFile("../Images/leon.png");
                            item2.sprite.setTexture(temp);
                            i++;
                            std::cout << i << "\n";
                            break;
                        case 7:
                            temp.loadFromFile("../Images/commander.png");
                            item2.sprite.setTexture(temp);
                            i++;
                            std::cout << i << "\n";
                            break;
                        case 8:
                            temp.loadFromFile("../Images/robi.png");
                            item2.sprite.setTexture(temp);
                            i++;
                            std::cout << i << "\n";
                            break;
                        case 9:
                            temp.loadFromFile("../Images/mrsghost.png");
                            item2.sprite.setTexture(temp);
                            i++;
                            std::cout << i << "\n";
                            break;
                        case 10:
                            temp.loadFromFile("../Images/professor.png");
                            item2.sprite.setTexture(temp);
                            i++;
                            std::cout << i << "\n";
                            break;
                        default:
                            break;

                        }

                        if (i == 4)
                        {
                            this->Status2 = false;
                            break;
                        }


                    }
                }
            }
        }
    }


}
/*
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
