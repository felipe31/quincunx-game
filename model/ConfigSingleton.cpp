#include "ConfigSingleton.hpp"
#include <iostream>

ConfigSingleton *ConfigSingleton::instance = 0;


ConfigSingleton::ConfigSingleton() {
    ballsAmount = 20;
    if (!primaryFont.loadFromFile("./res/fonts/ChicagoFlat.ttf")
        || !secondaryFont.loadFromFile("./res/fonts/ChicagoFlat-Italic.ttf"))
        std::cout << "Error while loading fonts\n";
}


sf::Font& ConfigSingleton::getPrimaryFont() {
    return primaryFont;
}
void ConfigSingleton::setPrimaryFont(sf::Font& newPrimaryFont) {
    primaryFont = newPrimaryFont;
}

sf::Font& ConfigSingleton::getSecondaryFont() {
    return secondaryFont;
}

void ConfigSingleton::setSecondaryFont(sf::Font& newSecondaryFont) {
    secondaryFont = newSecondaryFont;
}

int ConfigSingleton::getBallsAmount() {
    return ballsAmount;
}

