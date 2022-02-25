#include <SFML/Graphics.hpp>
#include <iostream>
#include<string>

int main()
{   
    sf::RenderWindow window(sf::VideoMode(960, 720), "Quincunx Game", sf::Style::Titlebar | sf::Style::Close);


    int bottomTextInfoY = 650;
    int bottomTextMainY = 660;

    sf::Font fontCasino;
    sf::Font fontCasinoFlatItalic;
    if (!fontCasino.loadFromFile("./res/fonts/Casino.ttf")
        || !fontCasinoFlatItalic.loadFromFile("./res/fonts/CasinoFlat-Italic.ttf"))
        std::cout << "Error while loading fonts\n";
    
    sf::Text textStart;
    // select the font
    textStart.setFont(fontCasino); // font is a sf::Font
    textStart.setString("START");
    textStart.setCharacterSize(50); // in pixels, not points!
    textStart.setFillColor(sf::Color::Red);
    textStart.setPosition(sf::Vector2f(50, bottomTextMainY));
        
    sf::Text textInfoStart;
    // select the font
    textInfoStart.setFont(fontCasinoFlatItalic); // font is a sf::Font
    textInfoStart.setString("Press spacebar to");
    textInfoStart.setCharacterSize(20); // in pixels, not points!
    textInfoStart.setFillColor(sf::Color::Red);
    textInfoStart.setPosition(sf::Vector2f(30, bottomTextInfoY));

    
    sf::Text textCreditsIn;
    // select the font
    textCreditsIn.setFont(fontCasino); // font is a sf::Font
    textCreditsIn.setString("Credits In");
    textCreditsIn.setCharacterSize(50); // in pixels, not points!
    textCreditsIn.setFillColor(sf::Color::Red);
    textCreditsIn.setPosition(sf::Vector2f(240, bottomTextMainY));
        
    sf::Text textInfoCreditsIn;
    // select the font
    textInfoCreditsIn.setFont(fontCasinoFlatItalic); // font is a sf::Font
    textInfoCreditsIn.setString("Press q to");
    textInfoCreditsIn.setCharacterSize(20); // in pixels, not points!
    textInfoCreditsIn.setFillColor(sf::Color::Red);
    textInfoCreditsIn.setPosition(sf::Vector2f(245, bottomTextInfoY));
    
    sf::Text textCreditsOut;
    // select the font
    textCreditsOut.setFont(fontCasino); // font is a sf::Font
    textCreditsOut.setString("Credits Out");
    textCreditsOut.setCharacterSize(50); // in pixels, not points!
    textCreditsOut.setFillColor(sf::Color::Red);
    textCreditsOut.setPosition(sf::Vector2f(500, bottomTextMainY));
        
    sf::Text textInfoCreditsOut;
    // select the font
    textInfoCreditsOut.setFont(fontCasinoFlatItalic); // font is a sf::Font
    textInfoCreditsOut.setString("Press w to");
    textInfoCreditsOut.setCharacterSize(20); // in pixels, not points!
    textInfoCreditsOut.setFillColor(sf::Color::Red);
    textInfoCreditsOut.setPosition(sf::Vector2f(505, bottomTextInfoY));

    sf::Text textCredits;
    // select the font
    textCredits.setFont(fontCasinoFlatItalic); // font is a sf::Font
    textCredits.setString("Credits");
    textCredits.setCharacterSize(20); // in pixels, not points!
    textCredits.setFillColor(sf::Color::Red);
    textCredits.setPosition(sf::Vector2f(800, bottomTextInfoY));

    sf::Text textValueCredits;
    // select the font
    textValueCredits.setFont(fontCasino); // font is a sf::Font
    textValueCredits.setString("0");
    textValueCredits.setCharacterSize(20); // in pixels, not points!
    textValueCredits.setFillColor(sf::Color::Yellow);
    textValueCredits.setPosition(sf::Vector2f(825, bottomTextMainY+15));



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

    ballHolderLeft.setPoint(0, sf::Vector2f(0.f, 0.f));
    ballHolderLeft.setPoint(1, sf::Vector2f(150.f, 90.f));
    ballHolderLeft.setPoint(2, sf::Vector2f(0.f, 90.f));

    ballHolderRight.setPoint(0, sf::Vector2f(350.f, 0.f));
    ballHolderRight.setPoint(1, sf::Vector2f(200.f, 90.f));
    ballHolderRight.setPoint(2, sf::Vector2f(350.f, 90.f));



    // Logical variables
    int credits = 0;

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
                // TODO understand if real-time input should be processed or event notifications are enough 
                switch (event.key.code)
                {
                case sf::Keyboard::Escape:
                    window.close();
                    break;
                case sf::Keyboard::Space:
                    textStart.setFillColor(sf::Color::Magenta);
                    textInfoStart.setFillColor(sf::Color::Magenta);
                    break;
                case sf::Keyboard::Q:
                    textCreditsIn.setFillColor(sf::Color::Magenta);
                    textInfoCreditsIn.setFillColor(sf::Color::Magenta);
                    break;
                case sf::Keyboard::W:
                    textCreditsOut.setFillColor(sf::Color::Magenta);
                    textInfoCreditsOut.setFillColor(sf::Color::Magenta);
                    break;
                }

                break;

            case sf::Event::KeyReleased:
                switch (event.key.code)
                {
                case sf::Keyboard::Q:
                    credits++;
                    textValueCredits.setString(std::to_string(credits));
                    textCreditsIn.setFillColor(sf::Color::Red);
                    textInfoCreditsIn.setFillColor(sf::Color::Red);

                    break;
                case sf::Keyboard::W:
                    credits = 0;
                    textValueCredits.setString(std::to_string(credits));
                    textCreditsOut.setFillColor(sf::Color::Red);
                    textInfoCreditsOut.setFillColor(sf::Color::Red);
                    break;
                case sf::Keyboard::Space:
                    textValueCredits.setString(std::to_string(credits));
                    textStart.setFillColor(sf::Color::Red);
                    textInfoStart.setFillColor(sf::Color::Red);
                    break;
                }
   
            }
        }
        window.clear(sf::Color::Black);
        window.draw(gameBoard);
        window.draw(ballHolderLeft);
        window.draw(ballHolderRight);
        window.draw(textInfoStart);
        window.draw(textStart);
        window.draw(textInfoCreditsIn);
        window.draw(textCreditsIn);
        window.draw(textInfoCreditsOut);
        window.draw(textCreditsOut);
        window.draw(textCredits);
        window.draw(textValueCredits);
        window.display();

    }
    return 0;
}
