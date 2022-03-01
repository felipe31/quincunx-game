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
    int64_t animationTime, totalElapsed; // in microseconds

public:
    GameBoard(sf::Vector2f boardPosition, int64_t animationTime);
    ~GameBoard(){};
    void update(int64_t elapsed);
    virtual void draw(sf::RenderTarget &window, sf::RenderStates state) const;

};
