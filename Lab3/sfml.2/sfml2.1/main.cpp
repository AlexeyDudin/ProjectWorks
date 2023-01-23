#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cmath>

constexpr unsigned WINDOW_WIDTH = 800;
constexpr unsigned WINDOW_HEIGHT = 600;

int main()
{
    constexpr float BALL_SIZE = 40;

    sf::RenderWindow window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "Title");
    sf::Clock clockx, clocky;

    sf::Vector2f startPosition = {10, 350};

    sf::CircleShape shape(BALL_SIZE);
    shape.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));
    sf::Vector2f offset = {0, 0};
    float speedX = 1000.f;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        constexpr float amplitudeY = 80.f;
        constexpr float periodY = 2;
        const float wavePhase = clocky.getElapsedTime().asSeconds() * float(2 * M_PI);

        float deltaTime = clockx.restart().asSeconds();
        float x = speedX * deltaTime;

        float y = amplitudeY * std::sin(wavePhase / periodY);
        offset.x += x;
        sf::Vector2f position = startPosition + offset;
        if ((position.x >= (WINDOW_WIDTH - 2 * BALL_SIZE)) || (position.x <= 0))
            speedX = -speedX;

        offset.y = y;

        shape.setPosition(position);

        window.clear();
        window.draw(shape);
        window.display();
    }
}