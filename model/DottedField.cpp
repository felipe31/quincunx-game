#include "DottedField.hpp"
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
    std::shared_ptr<sf::CircleShape> circle = std::make_shared<sf::CircleShape>(3);
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
    dotMatrix = std::vector<std::vector<std::shared_ptr<sf::CircleShape>>>();
    for (int i = 0; i < rows; ++i) {
            dotMatrix.push_back(std::vector<std::shared_ptr<sf::CircleShape>>(columns));
        for (int j = 0; j < columns; ++j) {
            if (i%2 != 0) {
                evenOddLine = spacing/2;
            } else {
                evenOddLine = 0;
            }

            dotMatrix[i][j] = DottedField::createDot(sf::Vector2f(start.x + evenOddLine + spacing * j, start.y + spacing / 2 * i));

        }
    }
}

bool DottedField::checkDotsCollision(Collider other) {
    int i = 0;
    for (auto itI = dotMatrix.begin(); itI != dotMatrix.end(); ++itI) {
        for (auto itJ = (*itI).begin(); itJ != (*itI).end(); ++itJ) {
            sf::CircleShape& dot = **itJ;
            Collider dotCollider(dot);

            // checkCollision MUST be called from "other"
            // otherwise, the dots will be moved in case of collision
            if (other.checkCollision(dotCollider)) {
                return true;
            }
        }
    }
    return false;
}
