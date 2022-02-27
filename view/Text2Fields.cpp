#include "Text2Fields.hpp"
#include <iostream>

Text2Fields::Text2Fields(std::string preString, std::string mainString,
                        sf::Vector2f prePosition, sf::Vector2f mainPosition,
                        sf::Font& preFont, sf::Font& mainFont,
                        int preSize, int mainSize)
    : preText(sf::Text(preString, preFont, preSize)),
      mainText(sf::Text(mainString, mainFont, mainSize)),
      prePosition(prePosition), mainPosition(mainPosition), isMainStringUpdater(false)
{
    primary = sf::Color::Red;
    secondary = sf::Color::Magenta;
    preText.setPosition(prePosition);
    mainText.setPosition(mainPosition);
    preText.setFillColor(primary);
    mainText.setFillColor(primary);
}

Text2Fields::~Text2Fields()
{
}

void Text2Fields::update(){
    if (isMainStringUpdater) {
        mainText.setString(mainStringUpdater());
    }
}

void Text2Fields::draw(sf::RenderTarget &window, sf::RenderStates state) const {
    window.draw(preText);
    window.draw(mainText);
}

void Text2Fields::FillColorPrimary() {
    preText.setFillColor(primary);
    mainText.setFillColor(primary);
}

void Text2Fields::setPrimary(sf::Color color) {
    primary = color;
    FillColorPrimary();
}

void Text2Fields::setSecondary(sf::Color color) {
    secondary = color;
}

void Text2Fields::FillColorSecondary() {
    preText.setFillColor(secondary);
    mainText.setFillColor(secondary);
}

void Text2Fields::setPreString(std::string preString) {
    preText.setString(preString);
}

std::string Text2Fields::getPreString(std::string preString) {
    return preText.getString();
}

void Text2Fields::setMainString(std::string mainString) {
    mainText.setString(mainString);
}
std::string  Text2Fields::getMainString(std::string mainString) {
    return mainText.getString();
}

void Text2Fields::setPrePosition(sf::Vector2f position) {
    prePosition = position;
}
sf::Vector2f Text2Fields::getPrePosition() {
    return prePosition;
}

void Text2Fields::setMainPosition(sf::Vector2f position) {
    mainPosition = position;
}
sf::Vector2f Text2Fields::getMainPosition() {
    return mainPosition;
}

void Text2Fields::setMainStringUpdater(std::function<std::string()> updater) {
    isMainStringUpdater = true;
    mainStringUpdater = updater;
}
