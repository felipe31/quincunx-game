#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "../model/Ball.hpp"

class FallingBalls {
private:
    std::vector<std::shared_ptr<Ball>> balls;
public:
    FallingBalls();
    ~FallingBalls();
    void addBall(sf::Vector2f position, sf::Color color);
    void drawBalls(sf::RenderTarget &window) const;
    void update();
    bool handleCollision(Collider& otherCollider);
};