#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({600, 800}), "Rectangles and circles");
    window.clear();

    //D
    sf::RectangleShape line1(sf::Vector2f(150, 5));
    line1.setPosition({5, 5});
    line1.rotate(90);
    line1.setFillColor(sf::Color(0xff, 0xff, 0xff));

    sf::RectangleShape line2(sf::Vector2f(75, 5));
    line2.rotate(20);
    line2.setFillColor(sf::Color(0xff, 0xff, 0xff));

    sf::RectangleShape line3(sf::Vector2f(100, 5));
    line3.setPosition({70, 25});
    line3.rotate(90);
    line3.setFillColor(sf::Color(0xff, 0xff, 0xff));

    sf::RectangleShape line4(sf::Vector2f(75, 5));
    line4.setPosition({70, 125});
    line4.rotate(155);
    line4.setFillColor(sf::Color(0xff, 0xff, 0xff));

    //A
    sf::RectangleShape line5(sf::Vector2f(165, 5));
    line5.setPosition({140, 5});
    line5.rotate(115);
    line5.setFillColor(sf::Color(0xff, 0xff, 0xff));

    sf::RectangleShape line6(sf::Vector2f(165, 5));
    line6.setPosition({140, 5});
    line6.rotate(65);
    line6.setFillColor(sf::Color(0xff, 0xff, 0xff));

    sf::RectangleShape line7(sf::Vector2f(115, 5));
    line7.setPosition({80, 125});
    //line7.rotate(65);
    line7.setFillColor(sf::Color(0xff, 0xff, 0xff));

    //Y
    sf::RectangleShape line8(sf::Vector2f(165, 5));
    line8.setPosition({300, 5});
    line8.rotate(115);
    line8.setFillColor(sf::Color(0xff, 0xff, 0xff));

    sf::RectangleShape line9(sf::Vector2f(85, 5));
    line9.setPosition({225, 5});
    line9.rotate(65);
    line9.setFillColor(sf::Color(0xff, 0xff, 0xff));

    window.draw(line1);
    window.draw(line2);
    window.draw(line3);
    window.draw(line4);
    window.draw(line5);
    window.draw(line6);
    window.draw(line7);
    window.draw(line8);
    window.draw(line9);

    window.display();

    sf::sleep(sf::seconds(5));
}