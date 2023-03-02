#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <functional>

class Text2Fields: public sf::Drawable {
private:
    sf::Vector2f prePosition, mainPosition;
    sf::Text preText, mainText;
    sf::Color primary, secondary;
    bool isMainStringUpdater;
    std::function<std::string()> mainStringUpdater;

public:
    Text2Fields(std::string preString, std::string mainString,
                sf::Vector2f prePosition, sf::Vector2f mainPosition,
                sf::Font& preFont, sf::Font& mainFont,
                int preSize = 20, int mainSize = 50);

    ~Text2Fields();
    void update();
    virtual void draw(sf::RenderTarget &window, sf::RenderStates state) const;

    void FillColorPrimary();
    void FillColorSecondary();

    void setPrimary(sf::Color color);
    void setSecondary(sf::Color color);

    void setPreString(std::string preString);
    std::string getPreString(std::string preString);

    void setMainString(std::string mainString);
    std::string getMainString(std::string mainString);

    void setPrePosition(sf::Vector2f position);
    sf::Vector2f getPrePosition();

    void setMainPosition(sf::Vector2f position);
    sf::Vector2f getMainPosition();

    void setMainStringUpdater(std::function<std::string()> updater);
};
