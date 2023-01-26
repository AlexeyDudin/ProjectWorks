#include "HealthInfo.h"

HealthInfo::HealthInfo()
{
}

HealthInfo::~HealthInfo()
{
}

void HealthInfo::Initialize(sf::RenderWindow& window, sf::RectangleShape parent, unsigned int health)
{
    if (!font.loadFromFile("C:\\Windows\\fonts\\arial.ttf"))
    {
        // error...
    }

    text.setString(L"Çהמנמגüו " + std::to_wstring(health) + L"%");
    sf::FloatRect textRect = text.getLocalBounds();

    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);

    text.setOrigin(textRect.left + textRect.width / 2.0f,
        textRect.top + textRect.height / 2.0f);
    text.setPosition(parent.getPosition().x + 20, 130);

    window.draw(text);
}

void HealthInfo::Render(sf::RenderWindow& window)
{
    window.draw(text);
}

void HealthInfo::Update(unsigned int health)
{
    text.setString(L"Çהמנמגüו " + std::to_wstring(health) + L"%");
}
