#include "LevelInfo.h"

LevelInfo::LevelInfo()
{
}

LevelInfo::~LevelInfo()
{
}

void LevelInfo::Initialize(sf::RenderWindow& window, sf::RectangleShape parent, int level)
{
    if (!font.loadFromFile("C:\\Windows\\fonts\\arial.ttf"))
    {
        // error...
    }

    text.setString(L"Уровень " + std::to_wstring(level));
    sf::FloatRect textRect = text.getLocalBounds();

    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);

    text.setOrigin(textRect.left + textRect.width / 2.0f,
        textRect.top + textRect.height / 2.0f);
    text.setPosition(parent.getPosition().x + 20, 100);

    window.draw(text);
}

void LevelInfo::Render(sf::RenderWindow& window)
{
    window.draw(text);
}
