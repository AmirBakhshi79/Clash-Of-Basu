#include "gamestate.h"

GameState::GameState(sf::RenderWindow* window , std::map<std::string, int>* SupportedKeys, std::stack<State*>* states)
    : State(window , SupportedKeys , states)
{
    ::x = 1460;
    ::m = 0;
    this->position11 = 1500;
    this->position21 = 35;
    ::position22 = 400;
    ::position12 = 400;
    this->initEntities();
    this->initTiles();
   // this->initBackGround();




    this->t1.loadFromFile("../Images/giant.png");
    this->t2.loadFromFile("../Images/snipper.png");
    this->t3.loadFromFile("../Images/drmarry.png");
    this->t4.loadFromFile("../Images/kratos.png");
    this->t5.loadFromFile("../Images/alphaman.png");
    this->t6.loadFromFile("../Images/leon.png");
    this->t7.loadFromFile("../Images/commander.png");
    this->t8.loadFromFile("../Images/robi.png");
    this->t9.loadFromFile("../Images/mrsghost.png");
    this->t10.loadFromFile("../Images/professor.png");

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

    for (auto &item1 : this->Entity1)
    {
        item1->render(target);
    }
    for (auto &item1 : this->Entity2)
    {
        item1->render(target);
    }

}

void GameState::updateTiles()
{
    for (auto &item1 : this->Tiles1)
    {
        for (auto &item2 : item1)
        {
            if (item2.sprite.getColor() != sf::Color::White)
            {
                item2.setColor(sf::Color::White);
                sf::Texture temp;
                temp.loadFromFile("../Images/Green.png");
                item2.setTexture(temp);
            }


        }
    }
    for (auto &item1 : this->Tiles2)
    {
        for (auto &item2 : item1)
        {
            if (item2.sprite.getColor() != sf::Color::White)
            {
                item2.setColor(sf::Color::White);
                sf::Texture temp;
                temp.loadFromFile("../Images/Green.png");
                item2.setTexture(temp);
            }

        }
    }

}

void GameState::selectTile()
{
    sf::Event event;
    while (this->window->pollEvent(event))
    {
        for (auto &item1 : this->Tiles1)
        {
            for (auto &item2 : item1)
            {
                if (item2.sprite.getGlobalBounds().contains(this->MousePositionView))
                {
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        item2.setColor(sf::Color::White);
                    }
                }
            }
        }
    }

}

void GameState::chooseTileForAttack()
{


}


void GameState::update(const float& dt)
{
    this->updateInput(dt);
    this->updateMousePosition();
    this->updateIcons();

    //this->updateTileIcons();
/*
    if (this->Status3)
    {
        this->updateTileIcons();
    }
    */
    if (this->Status1)
    {
        this->selectHero();
    }
    if (this->Status2)
    {
        this->selectTileForHero();
    }
    if (this->Status4)
    {

        this->selectHero2();
    }
    if (this->Status5)
    {
        this->selectTileForHero2();
    }
    if (this->startGane)
    {

        this->Play();
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
    for (unsigned short int i = 0; i < this->Entity1.size(); i++)
    {
        delete this->Entity1.at(i);
        this->Entity1.erase(this->Entity1.begin() + i);
    }
    for (unsigned short int i = 0; i < this->Entity2.size(); i++)
    {
        delete this->Entity2.at(i);
        this->Entity2.erase(this->Entity2.begin() + i);
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


    for (auto &counter1 : this->Tiles2)
    {
        for (auto &counter2 : counter1)
        {
            if (counter2.sprite.getGlobalBounds().contains(this->MousePositionView))
            {
               // std::cout << "Im Here\n";
                counter2.setColor(sf::Color::Red);
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    counter2.setColor(sf::Color::Blue);
                    for (auto &k : this->Tiles2)
                    {
                        for (auto &l : k)
                        {
                            if (l.y != counter2.y)
                            {
                                l.setColor(sf::Color::White);
                            }
                        }
                    }
                }
                for (auto &q : this->Tiles2)
                {
                    for (auto &w : q)
                    {
                        if (w.y != counter2.y)
                        {
                            w.setColor(sf::Color::White);
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
    static short int identifyNum2 = 1;
    unsigned short int y = 550;
    for (auto &item1 : this->Tiles1)
    {
        for (auto &item2 : item1)
        {
            item2.setPosition(::x,y);
            y = y + 51;
            item2.y = identifyNum;
            identifyNum++;
          //  std::cout << item2.y << std::endl;
          //  std::cout << item2.y << std::endl;
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
            item2.y = identifyNum2;
            identifyNum2++;
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
                        this->Entity1.push_back(new GiantHero("../Images/giant.png" , this->position11, ::position12));

                      //  this->Entities.erase(this->Entities.begin() + 0);

                        break;
                    case SNIPPER:
                        this->Heroes.push_back(2);
                        std::cout << "SNIPPER  "<<this->Heroes.size()<<"\n";
                        this->Entity1.push_back(new SnipperHero("../Images/snipper.png" , this->position11, ::position12));
                      //  this->Entities.erase(this->Entities.begin() + 1);
                        break;
                    case DRMARRY:
                        this->Heroes.push_back(3);
                        std::cout << "DRMARRY  "<<this->Heroes.size()<<"\n";
                        this->Entity1.push_back(new DrmarryHero("../Images/drmarry.png" , this->position11, ::position12));
                      //  this->Entities.erase(this->Entities.begin() + 2);
                        break;
                    case KRATOS:
                        this->Heroes.push_back(4);
                        std::cout << "KRATOS  "<<this->Heroes.size()<<"\n";
                        this->Entity1.push_back(new KratosHero("../Images/kratos.png" , this->position11, ::position12));
                      //  this->Entities.erase(this->Entities.begin() + 3);
                        break;
                    case ALPHAMAN:
                        this->Heroes.push_back(5);
                        std::cout << "ALPHAMAN  "<<this->Heroes.size()<<"\n";
                        this->Entity1.push_back(new AlphaManHero("../Images/alphaman.png" , this->position11, ::position12));
                       // this->Entities.erase(this->Entities.begin() + 4);
                        break;
                    case LEON:
                        this->Heroes.push_back(6);
                        std::cout << "LEON  "<<this->Heroes.size()<<"\n";
                        this->Entity1.push_back(new LeonHero("../Images/leon.png" , this->position11, ::position12));
                       // this->Entities.erase(this->Entities.begin() + 5);
                        break;
                    case COMMANDER:
                        this->Heroes.push_back(7);
                        std::cout << "COMMADNER  "<<this->Heroes.size()<<"\n";
                        this->Entity1.push_back(new CommanderHero("../Images/commander.png" , this->position11, ::position12));
                       // this->Entities.erase(this->Entities.begin() + 6);
                        break;
                    case ROBI:
                        this->Heroes.push_back(8);
                        std::cout << "ROBI  "<<this->Heroes.size()<<"\n";
                        this->Entity1.push_back(new SnipperHero("../Images/robi.png" , this->position11, ::position12));
                        //this->Entities.erase(this->Entities.begin() + 7);                       
                        break;

                    case MRSGHOST:
                        this->Heroes.push_back(9);
                        std::cout << "MRSGHOST  "<<this->Heroes.size()<<"\n";
                        this->Entity1.push_back(new MrsGhostHero("../Images/mrsghost.png" , this->position11, ::position12));
                        //this->Entities.erase(this->Entities.begin() + 8);
                        break;
                    case PROFESSOR:
                        this->Heroes.push_back(10);
                        std::cout << "PROFESSOR  "<<this->Heroes.size()<<"\n";
                        this->Entity1.push_back(new ProfessorHero("../Images/professor.png" , this->position11, ::position12));
                        //this->Entities.erase(this->Entities.begin() + 9);
                        break;

                    default:
                        break;

                    }
                    this->position11 = this->position11 + 80;
                    if (this->Heroes.size() == 5)
                    {
                        this->Status1 = false;
                        this->Status2 = true;
                        //this->Status3 = false;
                        //this->updateTiles();
                        this->x = 0;
                        break;
                    }
                }
            }
        }
    }

}

void GameState::selectTileForHero2()
{
    sf::Event event;
    static unsigned short int j = 0;
    //std::cout << "Enter\n";
    while (this->window->pollEvent(event) && this->y != 5)
    {

        for (auto &item1 : this->Tiles2)
        {
            for (auto &item2 : item1)
            {
                if (item2.sprite.getGlobalBounds().contains(this->MousePositionView))
                {

                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {


                        sf::Texture temp;
                        switch (this->Heroes2.at(j))
                        {
                        case 1:
                            temp.loadFromFile("../Images/giant.png");
                            item2.sprite.setTexture(temp);
                            item2.HeroesTexture = GIANTH;
                            j++;
                            std::cout << j << "\n";
                            break;
                        case 2:
                            temp.loadFromFile("../Images/snipper.png");
                            item2.sprite.setTexture(temp);
                            item2.HeroesTexture = SNIPPERH;
                            j++;
                            std::cout << j << "\n";
                            break;
                        case 3:
                            temp.loadFromFile("../Images/drmarry.png");
                            item2.sprite.setTexture(temp);
                            item2.HeroesTexture = DRMARRYH;
                            j++;
                            std::cout << j << "\n";
                            break;
                        case 4:
                            temp.loadFromFile("../Images/kratos.png");
                            item2.sprite.setTexture(temp);
                            item2.HeroesTexture = KRATOSH;
                            j++;
                            std::cout << j << "\n";
                            break;
                        case 5:
                            temp.loadFromFile("../Images/alphaman.png");
                            item2.sprite.setTexture(temp);
                            item2.HeroesTexture = ALPHAMANH;
                            j++;
                            std::cout << j << "\n";
                            break;
                        case 6:
                            temp.loadFromFile("../Images/leon.png");
                            item2.sprite.setTexture(temp);
                            item2.HeroesTexture = LEONH;
                            j++;
                            std::cout << j << "\n";
                            break;
                        case 7:
                            temp.loadFromFile("../Images/commander.png");
                            item2.sprite.setTexture(temp);
                            item2.HeroesTexture = COMMANDERH;
                            j++;
                            std::cout << j << "\n";
                            break;
                        case 8:
                            temp.loadFromFile("../Images/robi.png");
                            item2.sprite.setTexture(temp);
                            item2.HeroesTexture = ROBIH;
                            j++;
                            std::cout << j << "\n";
                            break;
                        case 9:
                            temp.loadFromFile("../Images/mrsghost.png");
                            item2.sprite.setTexture(temp);
                            item2.HeroesTexture = MRSGHOSTH;
                            j++;
                            std::cout << j << "\n";
                            break;
                        case 10:
                            temp.loadFromFile("../Images/professor.png");
                            item2.sprite.setTexture(temp);
                            item2.HeroesTexture = PROFESSORH;
                            j++;
                            std::cout << j << "\n";
                            break;
                        default:
                            break;

                        }


                        if (j == 5)
                        {
                            this->Status5 = false;
                            this->Status3 = false;
                            //this->updateTiles();
                            this->updateTiles();
                            this->selectTile();
                            this->startGane = true;
                            for (auto &m : this->Tiles2)
                            {
                                for (auto &n : m)
                                {
                                    if (n.HeroesTexture != NOT)
                                    {
                                        switch (n.HeroesTexture)
                                        {
                                        case GIANTH:
                                            n.sprite.setScale(0.8f,0.8f);
                                            n.sprite.setTexture(this->t1);

                                            break;
                                        case SNIPPERH:
                                            n.sprite.setScale(0.8f,0.8f);
                                            n.sprite.setTexture(this->t2);

                                            break;
                                        case COMMANDERH:
                                            n.sprite.setScale(0.8f,0.8f);
                                            n.sprite.setTexture(this->t7);

                                            break;
                                        case KRATOSH:
                                            n.sprite.setScale(0.8f,0.8f);
                                            n.sprite.setTexture(this->t4);

                                            break;
                                        case LEONH:
                                            n.sprite.setScale(0.8f,0.8f);
                                            n.sprite.setTexture(this->t6);

                                            break;
                                        case DRMARRYH:
                                            n.sprite.setScale(0.8f,0.8f);
                                            n.sprite.setTexture(this->t3);

                                            break;
                                        case MRSGHOSTH:
                                            n.sprite.setScale(0.8f,0.8f);
                                            n.sprite.setTexture(this->t9);

                                            break;
                                        case ROBIH:
                                            n.sprite.setScale(0.8f,0.8f);
                                            n.sprite.setTexture(this->t8);

                                            break;
                                        case ALPHAMANH:
                                            n.sprite.setScale(0.8f,0.8f);
                                            n.sprite.setTexture(this->t5);

                                            break;
                                        case PROFESSORH:
                                            n.sprite.setScale(0.8f,0.8f);
                                            n.sprite.setTexture(this->t10);

                                            std::cout << n.y << "\n";
                                            break;
                                        default:
                                            break;
                                        }
                                    }
                                }
                            }
                            break;
                        }


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
                             item2.HeroesTexture = GIANTH;
                             //item2.sprite.setScale(0.7f,0.7f);
                            // item2.sprite.setTexture(this->t1);

                            i++;
                            std::cout << i << "\n";
                            break;
                        case 2:
                             temp.loadFromFile("../Images/snipper.png");
                             item2.sprite.setTexture(temp);
                             item2.HeroesTexture = SNIPPERH;
                           // item2.sprite.setScale(0.8f,0.8f);
                           // item2.sprite.setTexture(this->t2);
                            i++;
                            std::cout << i << "\n";
                            break;
                        case 3:
                            temp.loadFromFile("../Images/drmarry.png");
                            item2.sprite.setTexture(temp);
                            item2.HeroesTexture = DRMARRYH;
                          //  item2.sprite.setScale(0.8f,0.8f);
                          //  item2.sprite.setTexture(this->t3);
                            i++;
                            std::cout << i << "\n";
                            break;
                        case 4:
                            temp.loadFromFile("../Images/kratos.png");
                            item2.sprite.setTexture(temp);
                            item2.HeroesTexture = KRATOSH;
                          //  item2.sprite.setScale(0.8f,0.8f);
                          //  item2.sprite.setTexture(this->t4);
                            i++;
                            std::cout << i << "\n";
                            break;
                        case 5:
                            temp.loadFromFile("../Images/alphaman.png");
                            item2.sprite.setTexture(temp);
                            item2.HeroesTexture = ALPHAMANH;
                          //  item2.sprite.setScale(0.8f,0.8f);
                         //   item2.sprite.setTexture(this->t5);
                            i++;
                            std::cout << i << "\n";
                            break;
                        case 6:
                            temp.loadFromFile("../Images/leon.png");
                            item2.sprite.setTexture(temp);
                            item2.HeroesTexture = LEONH;
                         //   item2.sprite.setScale(0.8f,0.8f);
                          //  item2.sprite.setTexture(this->t6);
                            i++;
                            std::cout << i << "\n";
                            break;
                        case 7:
                            temp.loadFromFile("../Images/commander.png");
                            item2.sprite.setTexture(temp);
                            item2.HeroesTexture = COMMANDERH;
                          //  item2.sprite.setScale(0.8f,0.8f);
                          //  item2.sprite.setTexture(this->t7);
                            i++;
                            std::cout << i << "\n";
                            break;
                        case 8:
                           temp.loadFromFile("../Images/robi.png");
                            item2.sprite.setTexture(temp);
                            item2.HeroesTexture = ROBIH;
                           // item2.sprite.setScale(0.8f,0.8f);
                          //  item2.sprite.setTexture(this->t8);
                            i++;
                            std::cout << i << "\n";
                            break;
                        case 9:
                           temp.loadFromFile("../Images/mrsghost.png");
                           item2.sprite.setTexture(temp);
                           item2.HeroesTexture = MRSGHOSTH;
                          //  item2.sprite.setScale(0.8f,0.8f);
                          //  item2.sprite.setTexture(this->t9);
                            i++;

                            std::cout << i << "\n";
                            break;
                        case 10:
                            temp.loadFromFile("../Images/professor.png");
                            item2.sprite.setTexture(temp);
                            item2.HeroesTexture = PROFESSORH;
                        //    item2.sprite.setScale(0.8f,0.8f);
                       //     item2.sprite.setTexture(this->t10);
                            i++;
                            std::cout << i << "\n";
                            break;
                        default:
                            break;

                        }
                        std::cout << this->Entity1.size() << " " << this->Heroes.size() << std::endl;
                        if (i == 5)
                        {
                            this->Status2 = false;
                           // this->updateTiles();

                            //static int HH = 1;
                            for (auto &i : this->Tiles1)
                            {
                                for (auto &j : i)
                                {
                                    switch (j.HeroesTexture)
                                    {
                                    case GIANTH:
                                        j.sprite.setScale(0.8f,0.8f);
                                        j.sprite.setTexture(this->t1);
                                        break;
                                    case SNIPPERH:
                                        j.sprite.setScale(0.7f,0.7f);
                                        j.sprite.setTexture(this->t2);
                                        break;
                                    case DRMARRYH:
                                        j.sprite.setScale(0.7f,0.7f);
                                        j.sprite.setTexture(this->t3);
                                        break;
                                    case COMMANDERH:
                                        j.sprite.setScale(0.8f,0.8f);
                                        j.sprite.setTexture(this->t7);
                                        break;
                                    case LEONH:
                                        j.sprite.setScale(0.8f,0.8f);
                                        j.sprite.setTexture(this->t6);
                                        break;
                                    case ALPHAMANH:
                                        j.sprite.setScale(0.8f,0.8f);
                                        j.sprite.setTexture(this->t5);
                                        break;
                                    case ROBIH:
                                        j.sprite.setScale(0.8f,0.8f);
                                        j.sprite.setTexture(this->t8);
                                        break;
                                    case PROFESSORH:
                                        j.sprite.setScale(0.8f,0.8f);
                                        j.sprite.setTexture(this->t10);
                                        break;
                                    case MRSGHOSTH:
                                        j.sprite.setScale(0.8f,0.8f);
                                        j.sprite.setTexture(this->t9);
                                        break;
                                    case KRATOSH:
                                        j.sprite.setScale(0.8f,0.8f);
                                        j.sprite.setTexture(this->t4);
                                    default:
                                        break;
                                    }
                                }

                            }
                           // std::cout << HH << std::endl;

                            break;
                        }


                    }
                }
            }
        }
    }


}

void GameState::Play()
{
    sf::Event event;
    while (this->window->pollEvent(event))
    {
        for (auto &item1 : this->Entity1)
        {
            if (item1->Hero.getGlobalBounds().contains(this->MousePositionView))
            {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {



                }
            }
        }
    }
}

void GameState::selectHero2()
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
                        this->Heroes2.push_back(1);
                        std::cout << "GIANT  "<<this->Heroes2.size()<<"\n";
                        this->Entity1.push_back(new GiantHero("../Images/giant.png" , this->position21, ::position22));
                        break;
                    case SNIPPER:
                        this->Heroes2.push_back(2);
                        std::cout << "SNIPPER  "<<this->Heroes2.size()<<"\n";
                        this->Entity2.push_back(new SnipperHero("../Images/snipper.png" , this->position21, ::position22));
                        break;
                    case DRMARRY:
                        this->Heroes2.push_back(3);
                        std::cout << "DRMARRY  "<<this->Heroes2.size()<<"\n";
                        this->Entity2.push_back(new DrmarryHero("../Images/drmarry.png" , this->position21, ::position22));
                        break;
                    case KRATOS:
                        this->Heroes2.push_back(4);
                        std::cout << "KRATOS  "<<this->Heroes2.size()<<"\n";
                        this->Entity2.push_back(new KratosHero("../Images/kratos.png" , this->position21, ::position22));
                        break;
                    case ALPHAMAN:
                        this->Heroes2.push_back(5);
                        std::cout << "ALPHAMAN  "<<this->Heroes2.size()<<"\n";
                        this->Entity2.push_back(new AlphaManHero("../Images/alphaman.png" , this->position21, ::position22));
                        break;
                    case LEON:
                        this->Heroes2.push_back(6);
                        std::cout << "LEON  "<<this->Heroes2.size()<<"\n";
                        this->Entity2.push_back(new LeonHero("../Images/leon.png" , this->position21, ::position22));
                        break;
                    case COMMANDER:
                        this->Heroes2.push_back(7);
                        std::cout << "COMMADNER  "<<this->Heroes2.size()<<"\n";
                        this->Entity2.push_back(new CommanderHero("../Images/commander.png" , this->position21, ::position22));
                        break;
                    case ROBI:
                        this->Heroes2.push_back(8);
                        std::cout << "ROBI  "<<this->Heroes2.size()<<"\n";
                        this->Entity2.push_back(new ROBIHero("../Images/robi.png" , this->position21, ::position22));
                        break;
                    case MRSGHOST:
                        this->Heroes2.push_back(9);
                        std::cout << "MRSGHOST  "<<this->Heroes2.size()<<"\n";
                        this->Entity2.push_back(new MrsGhostHero("../Images/mrsghost.png" , this->position21, ::position22));
                        break;
                    case PROFESSOR:
                        this->Heroes2.push_back(10);
                        std::cout << "PROFESSOR  "<<this->Heroes2.size()<<"\n";
                        this->Entity2.push_back(new ProfessorHero("../Images/professor.png" , this->position21, ::position22));
                        break;

                    default:
                        break;
                    }
                    this->position21 = this->position21 + 80;
                    if (this->Heroes2.size() == 5)
                    {
                        this->Status4 = false;
                        this->Status5 = true;
                        //this->Status3 = false;
                       // this->updateTiles();
                        break;
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


/*
void GameState::initBackGround()
{
    this->BackGroound.setSize(sf::Vector2f(
                                 static_cast<float>(this->window->getSize().x),
                                 static_cast<float> (this->window->getSize().y)
                                 )
                             );
    if (!this->BGtexture.loadFromFile("../Images/BG.jpg"))
        std::cout << "H\n";

    this->BackGroound.setTexture(&this->BGtexture);
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
