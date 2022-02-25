#include <SFML/Graphics.hpp>
#include <iostream>
int main()
{   
    sf::RenderWindow window(sf::VideoMode(), "Quincunx Game", sf::Style::Fullscreen);

    sf::Font font;
    if (!font.loadFromFile("./res/fonts/Casino.ttf"))
        std::cout << "Error while loading arial font\n";
    sf::Text textStart;

    // select the font
    textStart.setFont(font); // font is a sf::Font
    textStart.setString("START");
    textStart.setCharacterSize(100); // in pixels, not points!
    textStart.setFillColor(sf::Color::Red);

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
                if (event.key.code == sf::Keyboard::Escape)
                    window.close();
                break;
            }
        }
        window.clear(sf::Color::Black);
        window.draw(ballHolderLeft);
        window.draw(ballHolderRight);
        window.draw(textStart);
        window.display();

    }
    return 0;
}
