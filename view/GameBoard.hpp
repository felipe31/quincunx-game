#pragma once
#include <SFML/Graphics.hpp>
#include "DottedField.hpp"
#include "FallingBalls.hpp"
#include "../controller/Collider.hpp"

class GameBoard: public sf::Drawable {
private:
    sf::Vector2f boardPosition;
    sf::RectangleShape gameBoard, ground;
    DottedField dottedField;
    FallingBalls fallingBalls;
    Collider groundCollider;

public:
    GameBoard(sf::Vector2f boardPosition);
    ~GameBoard(){};
    void update();
    virtual void draw(sf::RenderTarget &window, sf::RenderStates state) const;

};
