#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "./view/Text2Lines.hpp"
#include "./model/GameStateSingleton.hpp"

std::string creditsUpdater() {
    GameStateSingleton &gameState = GameStateSingleton::getInstance();
    return std::to_string(gameState.getCreditsCurrent());
}

int main()
{   
    sf::RenderWindow window(sf::VideoMode(960, 720), "Quincunx Game", sf::Style::Titlebar | sf::Style::Close);


    int bottomTextY = 650;

    sf::Font fontCasino;
    sf::Font fontCasinoFlatItalic;
    if (!fontCasino.loadFromFile("./res/fonts/Casino.ttf")
        || !fontCasinoFlatItalic.loadFromFile("./res/fonts/CasinoFlat-Italic.ttf"))
        std::cout << "Error while loading fonts\n";

    Text2Lines startText("Press spacebar to", "Start",
                            sf::Vector2f(50, bottomTextY),
                            fontCasinoFlatItalic, fontCasino);

    Text2Lines creditsInText("Press q to", "Credits In",
                            sf::Vector2f(245, bottomTextY),
                            fontCasinoFlatItalic, fontCasino);


    Text2Lines creditsOutText("Press w to", "Credits Out",
                            sf::Vector2f(500, bottomTextY),
                            fontCasinoFlatItalic, fontCasino);


    Text2Lines creditsText("Credits", "0",
                            sf::Vector2f(800, bottomTextY),
                            fontCasinoFlatItalic, fontCasino);
    creditsText.setMainStringUpdater(creditsUpdater);

    sf::RectangleShape gameBoard(sf::Vector2f(940.f, 600.f));

    gameBoard.setFillColor(sf::Color::Transparent);
    gameBoard.setOutlineColor(sf::Color::White);
    gameBoard.setOutlineThickness(5);
    gameBoard.setPosition(sf::Vector2f(10, 40));

    // Ball holder
    sf::ConvexShape ballHolderLeft(3);
    sf::ConvexShape ballHolderRight(3);
    ballHolderLeft.setFillColor(sf::Color::Blue);
    ballHolderRight.setFillColor(sf::Color::Blue);

    ballHolderLeft.setPoint(0, sf::Vector2f(20.f, 50.f));
    ballHolderLeft.setPoint(1, sf::Vector2f(170.f, 140.f));
    ballHolderLeft.setPoint(2, sf::Vector2f(20.f, 140.f));

    ballHolderRight.setPoint(0, sf::Vector2f(370.f, 50.f));
    ballHolderRight.setPoint(1, sf::Vector2f(220.f, 140.f));
    ballHolderRight.setPoint(2, sf::Vector2f(370.f, 140.f));


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
                    std::cout << gameState.getCreditsCurrent();
                    std::cout << creditsUpdater();
                    break;
                case sf::Keyboard::W:
                    gameState.setCreditsOut(gameState.getCreditsOut() + gameState.getCreditsCurrent());
                    gameState.setCreditsCurrent(0);
                    creditsOutText.FillColorPrimary();
                    break;
                case sf::Keyboard::Space:
                    startText.FillColorPrimary();
                    break;
                }
                break;
            }
        }
        window.clear(sf::Color::Black);
        creditsText.update();
        window.draw(startText);
        window.draw(creditsText);
        window.draw(creditsInText);
        window.draw(creditsOutText);
        window.draw(gameBoard);
        window.draw(ballHolderLeft);
        window.draw(ballHolderRight);
        window.display();

    }
    return 0;
}
