#include "DistantionInfo.h"

DistantionInfo::DistantionInfo()
{
}

DistantionInfo::~DistantionInfo()
{
}

void DistantionInfo::Initialize(sf::RenderWindow& window, sf::RectangleShape parent, long distantion)
{
    if (!font.loadFromFile("C:\\Windows\\fonts\\arial.ttf"))
    {
        // error...
    }

    text.setString(L"Осталось: " + std::to_wstring(distantion) + L" метров");
    sf::FloatRect textRect = text.getLocalBounds();

    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);

    text.setOrigin(textRect.left + textRect.width / 2.0f,
        textRect.top + textRect.height / 2.0f);
    text.setPosition(parent.getPosition().x + 20, 200);

    window.draw(text);
}

void DistantionInfo::Render(sf::RenderWindow& window)
{
    window.draw(text);
}

void DistantionInfo::Update(long distantion)
{
    text.setString(L"Осталось: " + std::to_wstring(distantion) + L" метров");
}
