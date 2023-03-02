#include "GameBoard.hpp"
#include <functional>
#include "../model/ConfigSingleton.hpp"
#include "../model/GameStateSingleton.hpp"

GameBoard::GameBoard(sf::Vector2f boardPosition, int64_t animationTime, int64_t ballCreationInterval)
    : boardPosition(boardPosition), gameBoard(sf::Vector2f(940.f, 600.f)), dottedField(), creationElapsed(0),
        groundCollider(ground), animationElapsed(0), animationTime(animationTime), ballsAmount(0),
        ballCreationInterval(ballCreationInterval), isGameFinished(false) {

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
    ground.setPosition(sf::Vector2f(boardPosition.x, boardPosition.y + gameBoard.getSize().y - 50));

    groundCollider.setSize(ground.getSize());

    // Prizes
    createPrizeBoxes();

    // Ball color options
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

    for (int i = 0; i < prizeBoxes.size(); i++) {
        window.draw(prizeBoxes[i]);
    }

}

void GameBoard::update(int64_t elapsed) {
    animationElapsed += elapsed;
    creationElapsed += elapsed;

    // Handle ball creation
    if (creationElapsed > ballCreationInterval) {
        if(ballsAmount > 0) {
            fallingBalls.addBall(sf::Vector2f(boardPosition.x + gameBoard.getSize().x/2 - 20, boardPosition.y),
            ballColors[ballsAmount%ballColors.size()]);
            --ballsAmount;
        }
        creationElapsed -= ballCreationInterval;
    }

    // Handle ball animation
    if (animationElapsed > animationTime) {
        fallingBalls.update();
        fallingBalls.handleCollision(groundCollider);
        fallingBalls.handleDotsCollision(dottedField);
        animationElapsed -= animationTime;
    }

    // Check if the game has finished
    if (!isGameFinished) {
        isGameFinished = checkGameFinished();
        if(isGameFinished) {
            updateCredits();
        }
    }
}

void GameBoard::startGame(int amount) {
    ballsAmount = amount;
    isGameFinished = false;
    fallingBalls = FallingBalls();
};

bool GameBoard::getIsGameFinished() {
    return isGameFinished;
}

// Private methods
bool GameBoard::checkGameFinished() {
    if (fallingBalls.countBalls() > 0)
        return !fallingBalls.isAnyBallFalling();
    return false;
}

void GameBoard::updateCredits() {
    int points = fallingBalls.countPoints(prizeBoxes);
    GameStateSingleton& gameState = GameStateSingleton::getInstance();
    gameState.setCreditsCurrent(gameState.getCreditsCurrent() + points);
}

void GameBoard::createPrizeBoxes() {
    ConfigSingleton& configs = ConfigSingleton::getInstance();

    prizeBoxes.push_back(PrizeBox(5, configs.getPrimaryFont(),
        sf::Vector2f(ground.getPosition().x + ground.getSize().x / 10.f * 0, ground.getPosition().y),
        sf::Vector2f(ground.getSize().x / 10.f, gameBoard.getSize().y + boardPosition.y  - ground.getPosition().y),
        sf::Color::Blue));

    prizeBoxes.push_back(PrizeBox(1, configs.getPrimaryFont(),
        sf::Vector2f(ground.getPosition().x + ground.getSize().x / 10.f * 1, ground.getPosition().y),
        sf::Vector2f(ground.getSize().x / 10.f * 2, gameBoard.getSize().y + boardPosition.y  - ground.getPosition().y),
        sf::Color::Green));

    prizeBoxes.push_back(PrizeBox(0, configs.getPrimaryFont(),
        sf::Vector2f(ground.getPosition().x + ground.getSize().x / 10.f * 3, ground.getPosition().y),
        sf::Vector2f(ground.getSize().x / 10.f * 4, gameBoard.getSize().y + boardPosition.y  - ground.getPosition().y),
        sf::Color::Red));

    prizeBoxes.push_back(PrizeBox(1, configs.getPrimaryFont(),
        sf::Vector2f(ground.getPosition().x + ground.getSize().x / 10.f * 7, ground.getPosition().y),
        sf::Vector2f(ground.getSize().x / 10.f * 2, gameBoard.getSize().y + boardPosition.y  - ground.getPosition().y),
        sf::Color::Green));

    prizeBoxes.push_back(PrizeBox(5, configs.getPrimaryFont(),
        sf::Vector2f(ground.getPosition().x + ground.getSize().x / 10.f * 9, ground.getPosition().y),
        sf::Vector2f(ground.getSize().x / 10.f, gameBoard.getSize().y + boardPosition.y  - ground.getPosition().y),
        sf::Color::Blue));

}
