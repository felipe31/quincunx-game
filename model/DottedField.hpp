#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include "../controller/Collider.hpp"

class DottedField {
private:
    std::vector<std::vector<std::shared_ptr<sf::CircleShape>>> dotMatrix;
    
    void createDottedField(sf::Vector2f start, sf::Vector2f end, float spacing);
public:
    DottedField() { };
    DottedField(sf::Vector2f start, sf::Vector2f end, float spacing);
    ~DottedField();
    void drawDots(sf::RenderTarget &window) const;

    void fillDottedField(sf::Vector2f start, sf::Vector2f end, float spacing);

    static std::shared_ptr<sf::CircleShape> createDot(sf::Vector2f position);
    bool checkDotsCollision(Collider other);
};

