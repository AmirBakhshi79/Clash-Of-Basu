#include "aboutstate.h"

AboutState::AboutState(sf::RenderWindow* window , std::map<std::string, int>* SupportedKeys, std::stack<State*>* states) : State(window, SupportedKeys, states)
{
    this->initBackground();
    this->initFont();
    this->initButtons();
    this->Icons.push_back(new Giant("../Images/giant.png", 1000 ,200));
    this->Icons.push_back(new Snipper("../Images/snipper.png", 1100 ,200));
    this->Icons.push_back(new Kratos("../Images/kratos.png", 1200 ,200));
    this->Icons.push_back(new Leon("../Images/leon.png", 1300 ,200));
    this->Icons.push_back(new DrMarry("../Images/drmarry.png", 1400 ,200));
    this->Icons.push_back(new MrsGhost("../Images/mrsghost.png", 1000 ,600));
    this->Icons.push_back(new Robi("../Images/robi.png",1100,600));
    this->Icons.push_back(new AlphaMan("../Images/alphaman.png", 1200 ,600));
    this->Icons.push_back(new Professor("../Images/professor.png", 1300 ,600));
    this->Icons.push_back(new Commander("../Images/commander.png", 1400 ,600));


}

void AboutState::update(const float &dt)
{
    this->updateInput(dt);
    this->updateMousePosition();
}

void AboutState::render(sf::RenderTarget *target)
{
    target->draw(this->Background);
    for (auto &item : this->Icons)
    {
        item->render(target);
    }
    for (auto &item : this->buttons)
    {
        item.second->render(target);
    }

}

void AboutState::updateInput(const float &dt)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        this->endState();
}

void AboutState::initBackground()
{
    this->Background.setSize(sf::Vector2f(
                                 static_cast<float>(this->window->getSize().x),
                                 static_cast<float> (this->window->getSize().y)
                                 )
                             );
    this->BGtexture.loadFromFile("../Images/FF.jpg");
    this->Background.setTexture(&this->BGtexture);
}

void AboutState::initFont()
{
    if (!this->font.loadFromFile("../Font/JeanSunHo.ttf"))
    {
        std::cout << "Didnt load font from file...";
    }
}

void AboutState::initButtons()
{
    this->buttons["GIANT"] = new Button(1025, 300, 60, 50, "GIANT", &this->font, sf::Color(70,70,70,200) , sf::Color(150,150,150,225) , sf::Color(20,20,20,200));
    this->buttons["SNIPPER"] = new Button(1125, 300, 60, 50, "SNIPPER", &this->font, sf::Color(70,70,70,200) , sf::Color(150,150,150,225) , sf::Color(20,20,20,200));
    this->buttons["KRATOS"] = new Button(1225, 300, 60, 50, "KRATOS", &this->font, sf::Color(70,70,70,200) , sf::Color(150,150,150,225) , sf::Color(20,20,20,200));
    this->buttons["LEON"] = new Button(1325, 300, 60, 50, "LEON", &this->font, sf::Color(70,70,70,200) , sf::Color(150,150,150,225) , sf::Color(20,20,20,200));
    this->buttons["DRMARRY"] = new Button(1425, 300, 60, 50, "DRMARRY", &this->font, sf::Color(70,70,70,200) , sf::Color(150,150,150,225) , sf::Color(20,20,20,200));
    this->buttons["MRSGHOST"] = new Button(1025, 700, 60, 50, "MRSGHOST", &this->font, sf::Color(70,70,70,200) , sf::Color(150,150,150,225) , sf::Color(20,20,20,200));
    this->buttons["ROBI"] = new Button(1125, 700, 60, 50, "ROBI", &this->font, sf::Color(70,70,70,200) , sf::Color(150,150,150,225) , sf::Color(20,20,20,200));
    this->buttons["ALPHAMAN"] = new Button(1225, 700, 60, 50, "ALPHAMAN", &this->font, sf::Color(70,70,70,200) , sf::Color(150,150,150,225) , sf::Color(20,20,20,200));
    this->buttons["PROFESSOR"] = new Button(1325, 700, 60, 50, "PROFESSOR", &this->font, sf::Color(70,70,70,200) , sf::Color(150,150,150,225) , sf::Color(20,20,20,200));
    this->buttons["COMMANDER"] = new Button(1425, 700, 60, 50, "COMMANDER", &this->font, sf::Color(70,70,70,200) , sf::Color(150,150,150,225) , sf::Color(20,20,20,200));

}
AboutState::~AboutState()
{
    for (auto &item : this->Icons)
    {
        delete item;
    }
    auto it = this->buttons.begin();
    for (it = this->buttons.begin() ; it != this->buttons.end() ; ++it)
    {
        delete it->second;
    }
}
