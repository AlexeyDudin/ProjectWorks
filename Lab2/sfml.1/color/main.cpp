#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({40, 160}), "Rectangles and circles");

    window.clear();

    sf::RectangleShape shape0;
    shape0.setSize({100, 160});
    shape0.setRotation(0);
    shape0.setPosition({0, 0});
    shape0.setFillColor(sf::Color(0x80, 0x80, 0x80));
    window.draw(shape0);

    sf::CircleShape shape1(20);
    shape1.setPosition({25, 10});
    shape1.setFillColor(sf::Color(0xff, 0x00, 0x00));
    window.draw(shape1);
    // sf::RectangleShape shape1;
    // shape1.setSize({60, 20});
    // shape1.setRotation(75);
    // shape1.setPosition({200, 120});
    // shape1.setFillColor(sf::Color(0xff, 0x0, 0x0));
    // window.draw(shape1);

    sf::CircleShape shape2(20);
    shape2.setPosition({25, 60});
    shape2.setFillColor(sf::Color(0xff, 0xff, 0x00));
    window.draw(shape2);

    sf::CircleShape shape3(20);
    shape3.setPosition({25, 110});
    shape3.setFillColor(sf::Color(0x0, 0xff, 0x00));
    window.draw(shape3);

    // sf::RectangleShape shape3;
    // shape3.setSize({120, 15});
    // shape3.setRotation(-30);
    // shape3.setPosition({200, 120});
    // shape3.setFillColor(sf::Color(0xff, 0x00, 0xff));
    // window.draw(shape3);

    // sf::CircleShape shape4(75);
    // shape4.setPosition({330, 220});
    // shape4.setFillColor(sf::Color(0xff, 0xff, 0x0));
    // window.draw(shape4);

    window.display();

    sf::sleep(sf::seconds(5));
}