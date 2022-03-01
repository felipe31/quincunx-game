#pragma once
#include <SFML/Graphics.hpp>
#include "../controller/Collider.hpp"

class Ball : public sf::CircleShape {
private:
    float fallingSpeed, maxSpeed; // 1 means it reached max speed
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
};
