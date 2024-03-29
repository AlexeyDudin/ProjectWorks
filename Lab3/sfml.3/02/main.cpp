#include <SFML/Graphics.hpp>
#include <iostream>

void pollEvent(sf::RenderWindow &window)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::MouseButtonPressed:
            std::cout << "mouse pressed,"
                      << " x=" << event.mouseButton.x
                      << " y=" << event.mouseButton.y;
            break;
        case sf::Event::MouseButtonReleased:
            std::cout << "mouse released,"
                      << " x=" << event.mouseButton.x
                      << " y=" << event.mouseButton.y
                      << std::endl;
            break;
        }
    }
}

void redrawFrame(sf::RenderWindow &window)
{
    window.clear();
    window.display();
}

int main()
{
    constexpr unsigned WINDOW_WIDTH = 800;
    constexpr unsigned WINDOW_HEIGHT = 600;

    sf::RenderWindow window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "Print mouse coordinates");

    while (window.isOpen())
    {
        pollEvent(window);
        redrawFrame(window);
    }

    return 0;
}