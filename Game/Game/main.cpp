#include "World.h"
#include "Constants.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), L"Road runner", sf::Style::Default);
    bool isGameStarted = false;

    World* world = new World();
    world->Initialize(window);

    sf::Clock clock;
    sf::Clock timer;
    float startGameTime = 0;

    while (window.isOpen())
    {
        sf::Event event;
        
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyReleased)
            {
                if (event.key.code == sf::Keyboard::Space)
                {
                    isGameStarted = !isGameStarted;
                    if (isGameStarted)
                    {
                        world->EnableSound();
                    }
                    else
                    {
                        world->DisableSound();
                    }
                    timer.restart();
                }
            }
        }
        if (isGameStarted)
        { 
            float dt = clock.getElapsedTime().asSeconds();
            startGameTime += timer.getElapsedTime().asSeconds();

            timer.restart(); 
            clock.restart();

            window.clear();
            world->Update(event, dt, startGameTime);
            world->Render(window);
            if (world->isLevelComplete)
            {
                isGameStarted = false;
                world->IncrementLevel();
                timer.restart();
                clock.restart();
                startGameTime = 0;
                world->DisableSound();
            }
            else if (world->isGameOver)
            {
                isGameStarted = false;
                world->ResetLevel();
                timer.restart();
                clock.restart();
                startGameTime = 0;
                world->DisableSound();
            }
        }
        else
        {
            sf::Font font;
            if (!font.loadFromFile("C:\\Windows\\fonts\\arial.ttf"))
            {
                // error...
            }
            sf::Text text;
            text.setString(L"Для начала(продолжения) игры нажмите пробел");
            sf::FloatRect textRect = text.getLocalBounds();
                       
            text.setFont(font);
            text.setCharacterSize(24);
            text.setFillColor(sf::Color::White);
            text.setStyle(sf::Text::Bold);

            text.setOrigin(textRect.left + textRect.width / 2.0f,
                textRect.top + textRect.height / 2.0f);
            text.setPosition(sf::Vector2f(window.getView().getCenter().x - 7 * strlen("Для начала(продолжения) игры нажмите пробел"), window.getView().getCenter().y));

            window.clear();
            window.draw(text);
        }
        window.display();
    }
    return 0;
}