#include "Ball.hpp"

Ball::Ball(sf::Vector2f position, sf::Color color) {
    fallingSpeed = 0;
    maxSpeed = 0.5;
    isFalling = true;
    direction = 0;
    setRadius(38);
    lastCollisionY = getRadius() * -1;
    setFillColor(color);
    setPosition(position);
}

Ball::~Ball() {
}

Collider Ball::getCollider() {
    Collider collider = Collider((sf::Transformable&)*this);
    collider.setSize(sf::Vector2f(getRadius() * 2, getRadius() * 2));
    return collider;
}

void Ball::setFallingSpeed(float speed) {
    if (speed > maxSpeed) speed = maxSpeed;
    fallingSpeed = speed;
}

float Ball::getFallingSpeed() {
    return fallingSpeed;
}

void Ball::setIsFalling(bool falling) {
    isFalling = falling;
}

float Ball::getIsFalling() {
    return isFalling;
}

float Ball::getMaxSpeed() {
    return maxSpeed;
}

void Ball::setMaxSpeed(float speed) {
    maxSpeed = speed;
}

float Ball::getDirection() {
    return direction;
}
void Ball::setDirection(float newDirection) {
    direction = newDirection;
}


float Ball::getLastCollisionY() {
    return lastCollisionY;
}
void Ball::setLastCollisionY(float newCollision) {
    lastCollisionY = newCollision;
}