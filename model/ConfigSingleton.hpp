#pragma once
#include <SFML/Graphics.hpp>

class ConfigSingleton {
protected:
    ConfigSingleton();

    sf::Font primaryFont;
    sf::Font secondaryFont;
    int ballsAmount;
    static ConfigSingleton* instance;

public:
    static ConfigSingleton& getInstance() {
        if (instance == 0)
            instance = new ConfigSingleton();
        return *instance;
    }

    sf::Font& getPrimaryFont();
    void setPrimaryFont(sf::Font& newPrimaryFont);

    sf::Font& getSecondaryFont();
    void setSecondaryFont(sf::Font& newSecondaryFont);

    int getBallsAmount();

};