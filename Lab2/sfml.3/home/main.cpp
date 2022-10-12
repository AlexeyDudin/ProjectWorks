#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main()
{
    //sf::RenderWindow::Clear(sf::Color(0xFF, 0xFF, 0xFF));
    sf::RenderWindow window(sf::VideoMode({800, 1000}), "Title");
    //window.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));
    window.clear(sf::Color(0xFF, 0xFF, 0xFF));

    sf::RectangleShape mainHome;
    mainHome.setSize({600, 350});
    mainHome.setPosition({100, 600}); //4d2e0b
    mainHome.setFillColor(sf::Color(0x4D, 0x2E, 0x0B));

    window.draw(mainHome);

    sf::RectangleShape door;
    door.setSize({100, 250});
    door.setPosition({200, 700}); //181717
    door.setFillColor(sf::Color(0x18, 0x17, 0x17));
    window.draw(door);

    sf::ConvexShape roof;
    roof.setPointCount(4);
    roof.setPoint(0, {150, 400});
    roof.setPoint(1, {650, 400});
    roof.setPoint(3, {50, 600});
    roof.setPoint(2, {750, 600}); //5d1e17
    roof.setFillColor(sf::Color(0x5D, 0x1E, 0x17));
    window.draw(roof);

    sf::CircleShape shadow1(20);
    shadow1.setScale(2, 1.5);
    shadow1.setPosition(530, 245); //bfbfbf
    shadow1.setFillColor(sf::Color(0xBF, 0xBF, 0xBF));
    window.draw(shadow1);

    sf::CircleShape shadow2(40);
    shadow2.setPosition(550, 200); //bfbfbf
    shadow2.setFillColor(sf::Color(0xBF, 0xBF, 0xBF));
    window.draw(shadow2);

    sf::CircleShape shadow3(40);
    shadow3.setScale(1.2, 1);
    shadow3.setPosition(570, 150); //bfbfbf
    shadow3.setFillColor(sf::Color(0xBF, 0xBF, 0xBF));
    window.draw(shadow3);

    sf::CircleShape shadow4(40);
    shadow4.setScale(1.1, 1.2);
    shadow4.setPosition(590, 90); //bfbfbf
    shadow4.setFillColor(sf::Color(0xBF, 0xBF, 0xBF));
    window.draw(shadow4);

    sf::ConvexShape tube;
    tube.setPointCount(8);
    tube.setPoint(0, {500, 450});
    tube.setPoint(1, {500, 350});
    tube.setPoint(2, {450, 350});
    tube.setPoint(3, {450, 300});
    tube.setPoint(4, {650, 300});
    tube.setPoint(5, {650, 350});
    tube.setPoint(6, {600, 350});
    tube.setPoint(7, {600, 450}); //3b3838
    tube.setFillColor(sf::Color(0x3B, 0x38, 0x38));
    window.draw(tube);

    // sf::RectangleShape shape0;
    // shape0.setSize({100, 160});
    // shape0.setRotation(0);
    // shape0.setPosition({0, 0});
    // shape0.setFillColor(sf::Color(0x80, 0x80, 0x80));
    // window.draw(shape0);

    // sf::CircleShape shape1(20);
    // shape1.setPosition({25, 10});
    // shape1.setFillColor(sf::Color(0xff, 0x00, 0x00));
    // window.draw(shape1);
    // // sf::RectangleShape shape1;
    // // shape1.setSize({60, 20});
    // // shape1.setRotation(75);
    // // shape1.setPosition({200, 120});
    // // shape1.setFillColor(sf::Color(0xff, 0x0, 0x0));
    // // window.draw(shape1);

    // sf::CircleShape shape2(20);
    // shape2.setPosition({25, 60});
    // shape2.setFillColor(sf::Color(0xff, 0xff, 0x00));
    // window.draw(shape2);

    // sf::CircleShape shape3(20);
    // shape3.setPosition({25, 110});
    // shape3.setFillColor(sf::Color(0x0, 0xff, 0x00));
    // window.draw(shape3);

    // // sf::RectangleShape shape3;
    // // shape3.setSize({120, 15});
    // // shape3.setRotation(-30);
    // // shape3.setPosition({200, 120});
    // // shape3.setFillColor(sf::Color(0xff, 0x00, 0xff));
    // // window.draw(shape3);

    // // sf::CircleShape shape4(75);
    // // shape4.setPosition({330, 220});
    // // shape4.setFillColor(sf::Color(0xff, 0xff, 0x0));
    // // window.draw(shape4);

    window.display();

    sf::sleep(sf::seconds(5));
}