#include "TimerInfo.h"

int timeToFinish = 100;

TimerInfo::TimerInfo()
{
}

TimerInfo::~TimerInfo()
{
}

void TimerInfo::Initialize(sf::RenderWindow& window, sf::RectangleShape parent, int time)
{
    if (!font.loadFromFile("C:\\Windows\\fonts\\arial.ttf"))
    {
        // error...
    }

    text.setString(std::to_wstring(time) + L" сек.");
    sf::FloatRect textRect = text.getLocalBounds();

    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);

    text.setOrigin(textRect.left + textRect.width / 2.0f,
        textRect.top + textRect.height / 2.0f);
    text.setPosition(parent.getPosition().x + 20, window.getSize().y / 2 - 50);

    window.draw(text);
}

void TimerInfo::Render(sf::RenderWindow& window)
{
    window.draw(text);
}

void TimerInfo::Update(int time)
{
    text.setString(std::to_wstring(time) + L" сек.");
}
