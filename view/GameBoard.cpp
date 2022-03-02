#include "GameBoard.hpp"
#include <functional>
#include <iostream> // TEMP
GameBoard::GameBoard(sf::Vector2f boardPosition, int64_t animationTime, int64_t ballCreationInterval)
    : boardPosition(boardPosition), gameBoard(sf::Vector2f(940.f, 600.f)), dottedField(), creationElapsed(0),
        groundCollider(ground), animationElapsed(0), animationTime(animationTime), ballsAmount(0),
        ballCreationInterval(ballCreationInterval) {

    // Board outline
    gameBoard.setFillColor(sf::Color::Transparent);
    gameBoard.setOutlineColor(sf::Color::White);
    gameBoard.setOutlineThickness(5);
    gameBoard.setPosition(boardPosition);

    // Dotted field setup
    sf::Vector2f fieldStart = sf::Vector2f(boardPosition.x + gameBoard.getOutlineThickness() + 30,
        boardPosition.y + gameBoard.getOutlineThickness() + 100);

    sf::Vector2f fieldEnd = sf::Vector2f(boardPosition.x + gameBoard.getSize().x,
        boardPosition.y + gameBoard.getSize().y - 100);

    dottedField.fillDottedField(fieldStart, fieldEnd, 150);


    // Ground
    ground.setSize(sf::Vector2f(gameBoard.getSize().x, 10));
    ground.setPosition(sf::Vector2f(boardPosition.x, boardPosition.y + gameBoard.getSize().y));
    ground.setFillColor(sf::Color::Cyan); // TEMP

    groundCollider.setSize(ground.getSize());

    ballColors.push_back(sf::Color::Blue);
    ballColors.push_back(sf::Color::Green);
    ballColors.push_back(sf::Color::Magenta);
    ballColors.push_back(sf::Color::White);
    ballColors.push_back(sf::Color::Red);
}


void GameBoard::draw(sf::RenderTarget &window, sf::RenderStates state) const {
    window.draw(gameBoard);
    dottedField.drawDots(window);
    fallingBalls.drawBalls(window);
    window.draw(ground);
}

void GameBoard::update(int64_t elapsed) {
    animationElapsed += elapsed;
    creationElapsed += elapsed;
    if (creationElapsed > ballCreationInterval) {
        if(ballsAmount > 0) {
            fallingBalls.addBall(sf::Vector2f(boardPosition.x + gameBoard.getSize().x/2 - 20, boardPosition.y),
            ballColors[ballsAmount%ballColors.size()]);
            --ballsAmount;
        }
        creationElapsed -= ballCreationInterval;
    }
    if (animationElapsed > animationTime) {
        fallingBalls.update();
        fallingBalls.handleCollision(groundCollider);
        fallingBalls.handleDotsCollision(dottedField);
        animationElapsed -= animationTime;
    }
}

void GameBoard::startGame(int amount) {
    ballsAmount = amount;
    fallingBalls = FallingBalls();
};

bool GameBoard::isGameFinished() {
    if(fallingBalls.countBalls() > 0)
        return !fallingBalls.isAnyBallFalling();
    return false;
}