#include "aboutstate.h"

AboutState::AboutState(sf::RenderWindow* window , std::map<std::string, int>* SupportedKeys, std::stack<State*>* states) : State(window, SupportedKeys, states)
{
    this->initBackground();
    this->Icons.push_back(new Giant("../Images/giant.png", 1000 ,200));
    this->Icons.push_back(new Snipper("../Images/snipper.png", 1100 ,200));
    this->Icons.push_back(new Kratos("../Images/kratos.png", 1200 ,200));
    this->Icons.push_back(new Leon("../Images/leon.png", 1300 ,200));
    this->Icons.push_back(new DrMarry("../Images/drmarry.png", 1400 ,200));
    this->Icons.push_back(new MrsGhost("../Images/mrsghost.png", 1000 ,600));
    this->Icons.push_back(new Robi("../Images/robi.png",1100,600));
    this->Icons.push_back(new AlphaMan("../Images/alphaman.png", 1200 ,600));
    this->Icons.push_back(new Professor("../Images/professor.png", 1300 ,600));
    this->Icons.push_back(new Commander("../Images/professor.png", 1400 ,600));


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
AboutState::~AboutState()
{
    for (auto &item : this->Icons)
    {
        delete item;
    }
}
