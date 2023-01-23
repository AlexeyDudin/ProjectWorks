#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

float newAngle = 0;

void init(sf::ConvexShape &pointer)
{
    pointer.setPointCount(3);
    pointer.setPoint(0, {40, 0});
    pointer.setPoint(1, {-20, -20});
    pointer.setPoint(2, {-20, 20});
    pointer.setPosition({400, 300});
    pointer.setFillColor(sf::Color(0xFF, 0x80, 0x00));
}

float toDegrees(float radians)
{
    return float(double(radians) * 180.0 / M_PI);
}

void onMouseMove(const sf::Event::MouseMoveEvent &event, sf::Vector2f &mousePosition)
{
    std::cout << "mouse x=" << event.x << ", y=" << event.y << std::endl;

    //currAngle = atan2(mousePosition.y - 300, mousePosition.x - 400);
    newAngle = toDegrees(atan2(event.y - 300, event.x - 400));
    if (newAngle < 0)
        newAngle += 360;

    mousePosition = {float(event.x), float(event.y)};
}

void pollEvents(sf::RenderWindow &window, sf::Vector2f &mousePosition)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::MouseMoved:
            onMouseMove(event.mouseMove, mousePosition);
            break;
        default:
            break;
        }
    }
}

int GetDirection(float currAngle, float newAngle)
{
    if ((int)newAngle == (int)currAngle)
        return 0;
    int tmp = 1;
    if (abs(currAngle - newAngle) > 180)
        tmp = -1;
    if (currAngle - newAngle > 0)
        return tmp * -1;
    else
        return tmp * 1;
}

void update(const sf::Vector2f &mousePosition, sf::ConvexShape &pointer, float dt)
{
    const sf::Vector2f delta = mousePosition - pointer.getPosition();
    float direction = 0;
    float currAngle = pointer.getRotation();

    if (currAngle > 180)
        currAngle -= 360;
    if (newAngle > 180)
        newAngle -= 360;

    direction = GetDirection(currAngle, newAngle);

    std::cout << newAngle << " " << currAngle << " " << direction << std::endl;
    pointer.setRotation(pointer.getRotation() + (float)45 * dt * direction);
    // pointer.setRotation(toDegrees(newAngle - currAngle));
}

void redrawWindow(sf::RenderWindow &window, sf::ConvexShape &pointer)
{
    window.clear();
    window.draw(pointer);
    window.display();
}

int main()
{
    constexpr unsigned WINDOW_WIDTH = 800;
    constexpr unsigned WINDOW_HEIGHT = 600;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(
        sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}),
        "Pointer follows mouse",
        sf::Style::Default,
        settings);

    sf::ConvexShape pointer;
    sf::Vector2f mousePosition;

    sf::Clock clock;
    init(pointer);
    while (window.isOpen())
    {
        float dt = clock.restart().asSeconds();
        pollEvents(window, mousePosition);
        update(mousePosition, pointer, dt);
        redrawWindow(window, pointer);
    }
}