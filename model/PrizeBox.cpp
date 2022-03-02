#include "PrizeBox.hpp"

PrizeBox::PrizeBox(int prize, sf::Font& font, sf::Vector2f position, sf::Vector2f size, sf::Color color)
 : text(std::to_string(prize), font), rectangle(size), prize(prize) {

    rectangle.setPosition(position);
    rectangle.setFillColor(color);

    // Set position to the middle of the rectangle
    text.setPosition(sf::Vector2f(position.x + size.x/2 - std::to_string(prize).size()/2 * text.getCharacterSize()/2,
        position.y + size.y/2 - text.getCharacterSize()/2 - text.getCharacterSize()/6));
    text.setFillColor(sf::Color::Yellow);
    text.setOutlineThickness(5);
    text.setOutlineColor(sf::Color::Black);
    
}

PrizeBox::~PrizeBox() {
}

void PrizeBox::draw(sf::RenderTarget &window, sf::RenderStates state) const {
    window.draw(rectangle);
    window.draw(text);
}

sf::Vector2f PrizeBox::getPosition() {
    return rectangle.getPosition();
}
sf::Vector2f PrizeBox::getSize() {
    return rectangle.getSize();
}

int PrizeBox::getPrize() {
    return prize;
}
