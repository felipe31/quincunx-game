#include <SFML/Graphics.hpp>
#include "DottedField.hpp"

class GameBoard: public sf::Drawable {
private:
    sf::Vector2f boardPosition;
    sf::RectangleShape gameBoard;
    DottedField dottedField;

public:
    GameBoard(sf::Vector2f boardPosition);

    ~GameBoard(){};
    // void update();
    virtual void draw(sf::RenderTarget &window, sf::RenderStates state) const;

};
