#include "Ball.hpp"

Ball::Ball(sf::Vector2f position, sf::Color color) {
    fallingSpeed = 0;
    maxSpeed = 0.5;
    isFalling = true;
    setRadius(40);    
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