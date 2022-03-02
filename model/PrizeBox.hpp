#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class PrizeBox: public sf::Drawable  {
private:
    sf::RectangleShape rectangle;
    sf::Text text;
    int prize;

public:
    PrizeBox(int prize, sf::Font& font, sf::Vector2f position, sf::Vector2f size, sf::Color color);
    ~PrizeBox();
    void draw(sf::RenderTarget &window, sf::RenderStates state) const;
    sf::Vector2f getPosition();
    sf::Vector2f getSize();
    int getPrize();
};