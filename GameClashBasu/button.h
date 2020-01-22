#ifndef BUTTON_H
#define BUTTON_H

#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
enum StatusOfButton{BTN_COLORI = 0, BTN_COLORII, BTN_COLORIII};
class Button
{
private:
    short unsigned StatusOfButton;
    sf::RectangleShape buttonShape;
    sf::Font* font;
    sf::Text text;

    sf::Color Colori;
    sf::Color Colorii;
    sf::Color Coloriii;
public:
    const bool isPressed() const;
    Button(float x, float y, float width, float height,
           std::string text, sf::Font* font,
           sf::Color Colori, sf::Color Colorii, sf::Color Coloriii);
    void render(sf::RenderTarget * target);

    void update(const sf::Vector2f& MousePosition);
};

#endif // BUTTON_H
