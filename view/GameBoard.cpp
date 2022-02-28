#include "GameBoard.hpp"

GameBoard::GameBoard(sf::Vector2f boardPosition)
    : boardPosition(boardPosition), gameBoard(sf::Vector2f(940.f, 600.f)), dottedField() {

    gameBoard.setFillColor(sf::Color::Transparent);
    gameBoard.setOutlineColor(sf::Color::White);
    gameBoard.setOutlineThickness(5);
    gameBoard.setPosition(boardPosition);

    sf::Vector2f fieldStart = sf::Vector2f(boardPosition.x + gameBoard.getOutlineThickness() + 30,
        boardPosition.y + gameBoard.getOutlineThickness() + 100);

    sf::Vector2f fieldEnd = sf::Vector2f(boardPosition.x + gameBoard.getSize().x,
        boardPosition.y + gameBoard.getSize().y - 100);

    dottedField.fillDottedField(fieldStart, fieldEnd, 100);
}


void GameBoard::draw(sf::RenderTarget &window, sf::RenderStates state) const {
    window.draw(gameBoard);
    dottedField.drawDots(window);
}

