#include "Text2Lines.hpp"

Text2Lines::Text2Lines(std::string preString, std::string mainString,
                        sf::Vector2f position,
                        sf::Font& preFont, sf::Font& mainFont,
                        int preSize, int mainSize)
    : preText(sf::Text(preString, preFont, preSize)),
      mainText(sf::Text(mainString, mainFont, mainSize)),
      position(position), isMainStringUpdater(false)
{
    preText.setPosition(position);
    mainText.setPosition(sf::Vector2f(position.x, position.y + preText.getCharacterSize()));
    preText.setFillColor(sf::Color::Red);
    mainText.setFillColor(sf::Color::Red);
}

Text2Lines::~Text2Lines()
{
}

void Text2Lines::update(){
    if (isMainStringUpdater) {
        FillColorPrimary();
        mainText.setString(mainStringUpdater());
        FillColorSecondary();
    }
}

void Text2Lines::draw(sf::RenderTarget &window, sf::RenderStates state) const {
    window.draw(preText);
    window.draw(mainText);
}

void Text2Lines::FillColorPrimary() {
    preText.setFillColor(sf::Color::Red);
    mainText.setFillColor(sf::Color::Red);
}

void Text2Lines::FillColorSecondary() {
    preText.setFillColor(sf::Color::Magenta);
    mainText.setFillColor(sf::Color::Magenta);
}

void Text2Lines::setPreString(std::string preString) {
    preText.setString(preString);
}

std::string Text2Lines::getPreString(std::string preString) {
    return preText.getString();
}

void Text2Lines::setMainString(std::string mainString) {
    mainText.setString(mainString);
}
std::string  Text2Lines::getMainString(std::string mainString) {
    return mainText.getString();
}

void Text2Lines::setMainStringUpdater(std::function<std::string()> updater) {
    isMainStringUpdater = true;
    mainStringUpdater = updater;
}
