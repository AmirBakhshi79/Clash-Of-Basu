#include "mainmenu.h"

MainMenu::MainMenu(sf::RenderWindow* window , std::map<std::string, int>* SupportedKeys, std::stack<State*>* states)
    : State(window , SupportedKeys, states)
{

    this->initFont();
    this->initButtons();
    this->initBackGround();

}

void MainMenu::render(sf::RenderTarget* target)
{
    target->draw(this->BackGround);
    this->renderButtons(target);
}
void MainMenu::update(const float& dt)
{
    this->updateMousePosition();
    this->updateInput(dt);
    this->updateButtons();
    //this->renderButtons(this->window);

    //std::cout << this->MousePositionView.x << " " << this->MousePositionView.y << std::endl;
   // this->Button1->update(this->MousePositionView);

}

MainMenu::~MainMenu()
{
    auto it = this->buttons.begin();
    for (it = this->buttons.begin() ; it != this->buttons.end() ; ++it)
    {
        delete it->second;
    }
}
void MainMenu::updateInput(const float &dt)
{
    //this->checkForQuit();
}
void MainMenu::initFont()
{
    if (!this->font.loadFromFile("../Font/s.ttf"))
    {
        std::cout << "Didnt load font from file...";
    }
}
void MainMenu::initButtons()
{
    this->buttons["ABOUT_STATE"] = new Button(100, 200, 150, 50, "About", &this->font, sf::Color(70,70,70,200) , sf::Color(150,150,150,225) , sf::Color(20,20,20,200));
    this->buttons["GAME_STATE"] = new Button(100, 100, 150, 50, "New Game", &this->font, sf::Color(70,70,70,200) , sf::Color(150,150,150,225) , sf::Color(20,20,20,200));
    this->buttons["EXIT_STATE"] = new Button(100, 300, 150, 50, "Quit", &this->font, sf::Color(70,70,70,200) , sf::Color(150,150,150,225) , sf::Color(20,20,20,200));
}
void MainMenu::updateButtons()
{
    for (auto &item : this->buttons)
    {
        item.second->update(this->MousePositionView);


    }
    if (this->buttons["GAME_STATE"]->isPressed())
    {
        this->states->push(new GameState(this->window, this->SupportedKeys, this->states));
    }
    if (this->buttons["EXIT_STATE"]->isPressed())
    {
        this->endState();
    }


}
void MainMenu::initBackGround()
{
    this->BackGround.setSize(sf::Vector2f(
                                 static_cast<float>(this->window->getSize().x),
                                 static_cast<float> (this->window->getSize().y)
                                 )
                             );
    this->BGtexture.loadFromFile("../Images/BG.jpg");
    this->BackGround.setTexture(&this->BGtexture);
}
void MainMenu::renderButtons(sf::RenderTarget *target)
{
    for (auto &item : this->buttons)
    {
        item.second->render(target);
    }
}

