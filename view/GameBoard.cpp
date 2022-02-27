#include "GameBoard.hpp"

GameBoard::GameBoard(sf::Vector2f boardPosition)
    : boardPosition(boardPosition), gameBoard(sf::Vector2f(940.f, 600.f)) {

    gameBoard.setFillColor(sf::Color::Transparent);
    gameBoard.setOutlineColor(sf::Color::White);
    gameBoard.setOutlineThickness(5);
    gameBoard.setPosition(boardPosition);

}


void GameBoard::draw(sf::RenderTarget &window, sf::RenderStates state) const {
    window.draw(gameBoard);
}
