#include <SFML/Graphics.hpp>
#include "DottedField.hpp"
#include "FallingBalls.hpp"

class GameBoard: public sf::Drawable {
private:
    sf::Vector2f boardPosition;
    sf::RectangleShape gameBoard;
    DottedField dottedField;
    FallingBalls fallingBalls;

public:
    GameBoard(sf::Vector2f boardPosition);
    ~GameBoard(){};
    void update();
    virtual void draw(sf::RenderTarget &window, sf::RenderStates state) const;

};
