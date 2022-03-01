#include "FallingBalls.hpp"

FallingBalls::FallingBalls(/* args */) {
}

FallingBalls::~FallingBalls() {
}

void FallingBalls::addBall(sf::Vector2f position, sf::Color color) {
    balls.push_back(std::make_shared<Ball>(position, color));
}

void FallingBalls::drawBalls(sf::RenderTarget &window) const {
    for (int i = 0; i < balls.size(); ++i) {
        window.draw(*balls[i]);
    }
}

void FallingBalls::update() {
    
    for(auto it = balls.begin(); it != balls.end(); ++it) {
        Ball& ball = **it;
        if(ball.getIsFalling()) {
            if(ball.getFallingSpeed() != 1) {
                ball.setFallingSpeed(ball.getFallingSpeed()+0.001);
            }

            ball.setPosition(sf::Vector2f(ball.getPosition().x, ball.getPosition().y + ball.getFallingSpeed()));
            if(ball.getPosition().y > 610) ball.setIsFalling(false);
        }
    }
}