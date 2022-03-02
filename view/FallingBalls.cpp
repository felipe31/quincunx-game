#include "FallingBalls.hpp"
#include <ctime>

FallingBalls::FallingBalls() {
    std::srand( ( unsigned int )std::time( nullptr ) );
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
            if(ball.getFallingSpeed() != ball.getMaxSpeed()) {
                ball.setFallingSpeed(ball.getFallingSpeed()+0.0001);
            }

            ball.setPosition(sf::Vector2f(ball.getPosition().x + ball.getDirection(), ball.getPosition().y + ball.getFallingSpeed()));
        }
    }
}

void FallingBalls::handleCollision(Collider& otherCollider) {
    for(auto it = balls.begin(); it != balls.end(); ++it) {
        Ball& ball = **it;
        if(ball.getCollider().checkCollision(otherCollider))
            ball.setIsFalling(false);
    }
}

void FallingBalls::handleDotsCollision(DottedField& dottedField) {
    for(auto it = balls.begin(); it != balls.end(); ++it) {
        Ball& ball = **it;
        if(ball.getLastCollisionY() < ball.getPosition().y - 25) {
            if(dottedField.checkDotsCollision(ball.getCollider())) {
                ball.setLastCollisionY(ball.getPosition().y);
                // Randomly changes the ball's direction
                if(((std::rand() %2)+1)%2) {
                    ball.setDirection(-0.2);
                } else
                    ball.setDirection(0.2);

            }
        }
    }
}

