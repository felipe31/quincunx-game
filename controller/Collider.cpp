#include "Collider.hpp"
#include <iostream> // TEMP

Collider::Collider(sf::Transformable &body)
    : body(body), size() {
}

Collider::~Collider() {
}

// AABB collision
bool Collider::checkCollision(Collider& other) {

    sf::Vector2f otherPosition = sf::Vector2f(other.getPosition().x + other.getHalfSize().x,
        other.getPosition().y + other.getHalfSize().y);
    sf::Vector2f otherHalfSize = other.getHalfSize();

    sf::Vector2f thisPosition = sf::Vector2f(getPosition().x + getHalfSize().x,
        getPosition().y + getHalfSize().y);;
    sf::Vector2f thisHalfSize = getHalfSize();

    float deltaX = otherPosition.x - thisPosition.x;
    float deltaY = otherPosition.y - thisPosition.y;

    float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
    float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

    if (intersectX < 0.0f && intersectY < 0.0f) {

        if(intersectX > intersectY) {
            if(deltaX > 0.0f) {
                move(intersectX, 0.0f);
            } else {
                move(-intersectX, 0.0f);
            }
        } else {
            if(deltaY > 0.0f) {
                move(0.0f, intersectY);
            } else {
                move(0.0f, -intersectY);
            }
        }
        return true;
    }
    return false;
}

void Collider::move(float dx, float dy) {
    body.move(dx, dy);
}


sf::Vector2f Collider::getPosition() {
    return body.getPosition();
}
sf::Vector2f Collider::getHalfSize() {
    return size / 2.0f;
}

void Collider::setSize(sf::Vector2f newSize) {
    size = newSize;
}
