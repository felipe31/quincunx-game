#include "Collider.hpp"
#include <iostream>

Collider::Collider(sf::Transformable &body)
    : body(body), size() {
}

Collider::~Collider() {
}

bool Collider::checkCollision(Collider& other, float push) {

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
        push = std::min(std::max(push, 0.0f), 1.0f);

        if(intersectX > intersectY) {
            if(deltaX > 0.0f) {
                move(intersectX * (1.0f - push), 0.0f);
                other.move(-intersectX * push, 0.0f);
            } else {
                move(-intersectX * (1.0f - push), 0.0f);
                other.move(intersectX * push, 0.0f);
            }
        } else {
            if(deltaY > 0.0f) {
                move(0.0f, intersectY * (1.0f - push));
                other.move(0.0f, -intersectY * push);
            } else {
                move(0.0f, -intersectY * (1.0f - push));
                other.move(0.0f, intersectY * push);
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