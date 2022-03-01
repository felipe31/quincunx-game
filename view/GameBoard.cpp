#include "GameBoard.hpp"

GameBoard::GameBoard(sf::Vector2f boardPosition)
    : boardPosition(boardPosition), gameBoard(sf::Vector2f(940.f, 600.f)), dottedField() {

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

    // Falling Balls
    // TODO: Move this section to a "start" function
    fallingBalls.addBall(sf::Vector2f(boardPosition.x + gameBoard.getSize().x/2, boardPosition.y), sf::Color::Cyan);
    fallingBalls.addBall(sf::Vector2f(boardPosition.x + gameBoard.getSize().x/2 - 80, boardPosition.y), sf::Color::White);
    fallingBalls.addBall(sf::Vector2f(boardPosition.x + gameBoard.getSize().x/2 - 140, boardPosition.y), sf::Color::Blue);
    fallingBalls.addBall(sf::Vector2f(boardPosition.x + gameBoard.getSize().x/2 + 80, boardPosition.y), sf::Color::Red);
    fallingBalls.addBall(sf::Vector2f(boardPosition.x + gameBoard.getSize().x/2 - 20, boardPosition.y), sf::Color::Yellow);
    fallingBalls.addBall(sf::Vector2f(boardPosition.x + gameBoard.getSize().x/2 + 140, boardPosition.y), sf::Color::Green);
    fallingBalls.addBall(sf::Vector2f(boardPosition.x + gameBoard.getSize().x/2 + 20, boardPosition.y), sf::Color::Magenta);

}


void GameBoard::draw(sf::RenderTarget &window, sf::RenderStates state) const {
    window.draw(gameBoard);
    dottedField.drawDots(window);
    fallingBalls.drawBalls(window);
}

void GameBoard::update() {
    fallingBalls.update();
}

