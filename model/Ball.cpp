#include "Ball.hpp"

Ball::Ball(sf::Vector2f position, sf::Color color) {
    fallingSpeed = 0;
    isFalling = true;
    setRadius(10);    
    setFillColor(color);
    setPosition(position);
}

Ball::~Ball() {
}

void Ball::setFallingSpeed(float speed) {
    if (speed > 1) speed = 1;
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