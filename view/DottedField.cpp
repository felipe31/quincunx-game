#include "DottedField.hpp"
#include <iostream>
#include <string>

DottedField::DottedField(sf::Vector2f start, sf::Vector2f end, float spacing) {
    createDottedField(start, end, spacing);
}

DottedField::~DottedField() {
}


void DottedField::drawDots(sf::RenderTarget &window) const {

    for (int i = 0; i < dotMatrix.size(); ++i) {
        for (int j = 0; j < dotMatrix[i].size(); ++j) {
            window.draw(*dotMatrix[i][j]);
        }

    }
}

std::shared_ptr<sf::CircleShape> DottedField::createDot(sf::Vector2f position) {
    std::shared_ptr<sf::CircleShape> circle = std::make_shared<sf::CircleShape>(5);
    (*circle).setPosition(position);
    (*circle).setFillColor(sf::Color::White);
    return circle;
}

void DottedField::fillDottedField(sf::Vector2f start, sf::Vector2f end, float spacing) {
    createDottedField(start, end, spacing);
}



void DottedField::createDottedField(sf::Vector2f start, sf::Vector2f end, float spacing) {

    int rows = 0.5 + (end.y - start.y) / (spacing / 2);
    int columns = 0.5 + (end.x - start.x) / spacing;

    int evenOddLine = 0;
    dotMatrix = std::vector<std::vector<std::shared_ptr<sf::Drawable>>>();
    std::cout << "Columns: " << columns << " Rows: " << rows << "\n"; 
    for (int i = 0; i < rows; ++i) {
            dotMatrix.push_back(std::vector<std::shared_ptr<sf::Drawable>>(columns));
        for (int j = 0; j < columns; ++j) {
            sf::CircleShape cirecle(10);
            if (i%2 != 0) {
                evenOddLine = spacing/2;
            } else {
                evenOddLine = 0;
            }

            dotMatrix[i][j] = DottedField::createDot(sf::Vector2f(start.x + evenOddLine + spacing * j, start.y + spacing / 2 * i));

        }
    }
}