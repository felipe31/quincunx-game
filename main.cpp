#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "./view/Text2Fields.hpp"
#include "./model/GameStateSingleton.hpp"
#include "./view/GameBoard.hpp"

std::string creditsCurrentUpdater() {
    GameStateSingleton &gameState = GameStateSingleton::getInstance();
    return std::to_string(gameState.getCreditsCurrent());
}


std::string creditsInsertedTotalUpdater() {
    GameStateSingleton &gameState = GameStateSingleton::getInstance();
    return std::to_string(gameState.getCreditsIn());
}

std::string creditsRemovedUpdater() {
    GameStateSingleton &gameState = GameStateSingleton::getInstance();
    return std::to_string(gameState.getCreditsOut());
}

std::string matchesPlayedUpdater() {
    GameStateSingleton &gameState = GameStateSingleton::getInstance();
    return std::to_string(gameState.getMatchCount());
}
int main()
{   
    sf::RenderWindow window(sf::VideoMode(960, 720), "Quincunx Game", sf::Style::Titlebar | sf::Style::Close);


    int bottomTextY = 655;
    int topTextY = 5;

    sf::Font fontCasino;
    sf::Font fontCasinoFlatItalic;
    if (!fontCasino.loadFromFile("./res/fonts/ChicagoFlat.ttf")
        || !fontCasinoFlatItalic.loadFromFile("./res/fonts/ChicagoFlat-Italic.ttf"))
        std::cout << "Error while loading fonts\n";

    Text2Fields startText("Press spacebar to", "Start",
        sf::Vector2f(50, bottomTextY), sf::Vector2f(50, bottomTextY + 10),
        fontCasinoFlatItalic, fontCasino);

    Text2Fields creditsInText("Press q to", "Credits In",
        sf::Vector2f(245, bottomTextY), sf::Vector2f(245, bottomTextY + 10),
        fontCasinoFlatItalic, fontCasino);


    Text2Fields creditsOutText("Press w to", "Credits Out",
        sf::Vector2f(500, bottomTextY), sf::Vector2f(500, bottomTextY + 10),
        fontCasinoFlatItalic, fontCasino);


    Text2Fields creditsText("Credits", "0",
        sf::Vector2f(800, bottomTextY), sf::Vector2f(800, bottomTextY + 10),
        fontCasinoFlatItalic, fontCasino);

    creditsText.setMainStringUpdater(creditsCurrentUpdater);
    creditsText.setPrimary(sf::Color::Yellow);

    Text2Fields creditsInsertedTotalText("Total inserted:", "0",
        sf::Vector2f(10, topTextY), sf::Vector2f(150, topTextY),
        fontCasinoFlatItalic, fontCasino, 18, 18);
    creditsInsertedTotalText.setMainStringUpdater(creditsInsertedTotalUpdater);
    creditsInsertedTotalText.setPrimary(sf::Color::Yellow);

    Text2Fields creditsRemovedTotalText("Total removed:", "0",
        sf::Vector2f(400, topTextY), sf::Vector2f(540, topTextY),
        fontCasinoFlatItalic, fontCasino, 18, 18);
    creditsRemovedTotalText.setMainStringUpdater(creditsRemovedUpdater);
    creditsRemovedTotalText.setPrimary(sf::Color::Yellow);
    
    Text2Fields matchTotalText("Matches played:", "0",
        sf::Vector2f(770, topTextY), sf::Vector2f(920, topTextY),
        fontCasinoFlatItalic, fontCasino, 18, 18);
    matchTotalText.setMainStringUpdater(matchesPlayedUpdater);
    matchTotalText.setPrimary(sf::Color::Yellow);


    GameBoard gameBoard = GameBoard(sf::Vector2f(10, 40));

    // Logical variables
    GameStateSingleton &gameState = GameStateSingleton::getInstance();

    // Game loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
         
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;

            // Key handling
            case sf::Event::KeyPressed:

                // Press Escape to quit the game
                switch (event.key.code)
                {
                case sf::Keyboard::Escape:
                    window.close();
                    break;
                case sf::Keyboard::Q:
                    creditsInText.FillColorSecondary();
                    break;
                case sf::Keyboard::W:
                    creditsOutText.FillColorSecondary();
                    break;
                case sf::Keyboard::Space:
                    startText.FillColorSecondary();
                    break;
                }
                break;

            case sf::Event::KeyReleased:
                switch (event.key.code)
                {
                case sf::Keyboard::Q:
                    gameState.setCreditsCurrent(gameState.getCreditsCurrent() + 1);
                    gameState.setCreditsIn(gameState.getCreditsIn() + 1);
                    creditsInText.FillColorPrimary();
                    break;
                case sf::Keyboard::W:
                    gameState.setCreditsOut(gameState.getCreditsOut() + gameState.getCreditsCurrent());
                    gameState.setCreditsCurrent(0);
                    creditsOutText.FillColorPrimary();
                    break;
                case sf::Keyboard::Space:
                    startText.FillColorPrimary();
                    if (gameState.getCreditsCurrent() > 0) {
                        gameState.setCreditsCurrent(gameState.getCreditsCurrent() - 1);
                        gameState.setMatchCount(gameState.getMatchCount() + 1);
                    }
                    break;
                }
                break;
            }
        }
        window.clear(sf::Color::Black);
        creditsText.update();
        creditsInsertedTotalText.update();
        creditsRemovedTotalText.update();
        matchTotalText.update();
        gameBoard.update();
        window.draw(gameBoard);
        window.draw(creditsInsertedTotalText);
        window.draw(creditsRemovedTotalText);
        window.draw(matchTotalText);
        window.draw(startText);
        window.draw(creditsText);
        window.draw(creditsInText);
        window.draw(creditsOutText);
        window.display();

    }
    return 0;
}
