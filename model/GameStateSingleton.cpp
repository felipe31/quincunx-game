#include "GameStateSingleton.hpp"

GameStateSingleton *GameStateSingleton::instance = 0;

int GameStateSingleton::getCreditsCurrent() {
    return creditsCurrent;
}
void GameStateSingleton::setCreditsCurrent(int newCreditsCurrent) {
    creditsCurrent = newCreditsCurrent;
}

int GameStateSingleton::getCreditsIn() {
    return creditsIn;
}
void GameStateSingleton::setCreditsIn(int newCreditsIn) {
    creditsIn = newCreditsIn;
}

int GameStateSingleton::getCreditsOut() {
    return creditsOut;
}
void GameStateSingleton::setCreditsOut(int newCreditsOut) {
    creditsOut = newCreditsOut;
}