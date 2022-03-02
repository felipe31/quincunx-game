#pragma once
#include <SFML/Graphics.hpp>

class Collider {
private:
    sf::Transformable& body;
    sf::Vector2f size;
public:
    Collider(sf::Transformable& body);
    ~Collider();

    bool checkCollision(Collider& other);
    sf::Vector2f getPosition();
    sf::Vector2f getHalfSize();
    void move(float dx, float dy);

    void setSize(sf::Vector2f newSize);
};
