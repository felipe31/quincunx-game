#include <SFML/Graphics.hpp>

class Ball : public sf::CircleShape {
private:
    float fallingSpeed; // 1 means it reached max speed
    bool isFalling;

public:
    Ball(sf::Vector2f position, sf::Color color);
    ~Ball();
    void setFallingSpeed(float speed);
    float getFallingSpeed();
    void setIsFalling(bool falling);
    float getIsFalling();
};
