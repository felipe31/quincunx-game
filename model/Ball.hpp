#pragma once
#include <SFML/Graphics.hpp>
#include "../controller/Collider.hpp"

class Ball : public sf::CircleShape {
private:
    float fallingSpeed, maxSpeed, direction, lastCollisionY;
    bool isFalling;

public:
    Ball(sf::Vector2f position, sf::Color color);
    ~Ball();
    Collider getCollider();

    void setFallingSpeed(float speed);
    float getFallingSpeed();
    
    void setIsFalling(bool falling);
    float getIsFalling();
    
    void setMaxSpeed(float speed);
    float getMaxSpeed();

    float getDirection();
    void setDirection(float newDirection);

    float getLastCollisionY();
    void setLastCollisionY(float newCollision);
};
