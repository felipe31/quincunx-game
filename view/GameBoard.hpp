#pragma once
#include <SFML/Graphics.hpp>
#include "../model/DottedField.hpp"
#include "../model/PrizeBox.hpp"
#include "FallingBalls.hpp"
#include "../controller/Collider.hpp"

class GameBoard: public sf::Drawable {
private:
    sf::Vector2f boardPosition;
    sf::RectangleShape gameBoard, ground;
    DottedField dottedField;
    FallingBalls fallingBalls;
    Collider groundCollider;
    int64_t animationTime, animationElapsed, creationElapsed, ballCreationInterval; // in microseconds
    std::vector<sf::Color> ballColors;
    int ballsAmount;
    std::vector<PrizeBox> prizeBoxes;
    bool isGameFinished;

    bool checkGameFinished();
    void updateCredits();

public:
    GameBoard(sf::Vector2f boardPosition, int64_t animationTime, int64_t ballCreationInterval);
    ~GameBoard(){};
    void update(int64_t elapsed);
    virtual void draw(sf::RenderTarget &window, sf::RenderStates state) const;
    void startGame(int amount);
    void createPrizeBoxes();
    bool getIsGameFinished();
};
