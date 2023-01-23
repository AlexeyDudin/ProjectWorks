#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>

int main()
{
    constexpr int pointCount = 200; //ровные границы эллипса
    const sf::Vector2f ellipseRadius = {150.f, 20.f};
    sf::Clock clock;

    // Создаём окно с параметрами сглаживания
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode({800, 600}), "Polar Rose",
        sf::Style::Default, settings);

    // Объявляем фигуру
    sf::ConvexShape rose;
    rose.setFillColor(sf::Color(0xFF, 0x09, 0x80));

    // Рисуем розочку
    rose.setPointCount(pointCount);
    for (int pointNo = 0; pointNo < pointCount; ++pointNo)
    {
        float angle = float(2 * M_PI * pointNo) / float(pointCount);
        float ellipseRadius = pointCount * std::sin(6 * angle);
        sf::Vector2f point = {
            ellipseRadius * std::sin(angle),
            ellipseRadius * std::cos(angle)};
        rose.setPoint(pointNo, point);
    }

    float changedAngle = 0;
    const float radius = 50;
    sf::Vector2f startPos = {300, 300};
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

        const float deltaTime = clock.restart().asSeconds();

        changedAngle = changedAngle + deltaTime;

        float newX = startPos.x + radius * std::sin(changedAngle);
        float newY = startPos.y + radius * std::cos(changedAngle);

        rose.setPosition({newX, newY});

        window.clear();
        window.draw(rose);
        window.display();
    }
}