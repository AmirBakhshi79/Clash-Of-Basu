#include "button.h"

Button::Button(float x, float y, float width, float height,
               std::string text, sf::Font* font,
               sf::Color Colori, sf::Color Colorii, sf::Color Coloriii)
{
    this->StatusOfButton = BTN_COLORI;
    this->buttonShape.setSize(sf::Vector2f(width,height));
    this->buttonShape.setPosition(sf::Vector2f(x,y));
    this->font = font;
    this->text.setFont(*this->font);
    this->text.setString(text);
    this->text.setColor(sf::Color::White);
    this->text.setCharacterSize(20);
    this->text.setPosition(
                this->buttonShape.getPosition().x + (this->buttonShape.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f,
                this->buttonShape.getPosition().y + (this->buttonShape.getGlobalBounds().height / 2.f) - this->text.getGlobalBounds().height / 2.f
                );
    this->Colori = Colori;
    this->Colorii = Colorii;
    this->Coloriii = Coloriii;
    this->buttonShape.setFillColor(this->Colori);
}
void Button::render(sf::RenderTarget *target)
{
    target->draw(this->buttonShape);
    target->draw(this->text);
}
void Button::update(const sf::Vector2f& MousePosition)
{
    this->StatusOfButton = BTN_COLORI;
    if (this->buttonShape.getGlobalBounds().contains(MousePosition))
    {
        this->StatusOfButton = BTN_COLORII;
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            this->StatusOfButton = BTN_COLORIII;
        }
    }
    switch (this->StatusOfButton) {

    case BTN_COLORI:
        this->buttonShape.setFillColor(this->Colori);
        break;
    case BTN_COLORII:
        this->buttonShape.setFillColor(this->Colorii);
        break;
    case BTN_COLORIII:
        this->buttonShape.setFillColor(this->Coloriii);
        break;

    default:
        this->buttonShape.setFillColor(sf::Color::Red);
        break;
    }
}
const bool Button::isPressed() const
{
    if (this->StatusOfButton == BTN_COLORIII)
        return true;
    return false;
}
