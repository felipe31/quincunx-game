#include <SFML/Graphics.hpp>
#include <string>
#include <functional>

class Text2Lines: public sf::Drawable {
private:
    sf::Keyboard::Key triggerKey;
    sf::Vector2f position;
    sf::Text preText, mainText;
    bool isMainStringUpdater;
    std::function<std::string()> mainStringUpdater;

public:
    Text2Lines(std::string preString, std::string mainString,
                sf::Vector2f position,
                sf::Font& preFont, sf::Font& mainFont,
                int preSize = 20, int mainSize = 50);

    ~Text2Lines();
    void update();
    virtual void draw(sf::RenderTarget &window, sf::RenderStates state) const;

    void FillColorPrimary();
    void FillColorSecondary();

    void setPreString(std::string preString);
    std::string getPreString(std::string preString);

    void setMainString(std::string mainString);
    std::string getMainString(std::string mainString);
    
    void setMainStringUpdater(std::function<std::string()> updater);
};
