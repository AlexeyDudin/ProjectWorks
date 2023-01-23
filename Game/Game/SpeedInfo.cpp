#include "SpeedInfo.h"

SpeedInfo::SpeedInfo()
{
}

SpeedInfo::~SpeedInfo()
{
}

void SpeedInfo::Initialize(sf::RenderWindow& window, sf::RectangleShape parent, float speed)
{
    if (!font.loadFromFile("C:\\Windows\\fonts\\arial.ttf"))
    {
        // error...
    }
    
    text.setString(std::to_wstring((int)std::round(speed / 4)) + L" κμ/χ");
    sf::FloatRect textRect = text.getLocalBounds();

    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);

    text.setOrigin(textRect.left + textRect.width / 2.0f,
        textRect.top + textRect.height / 2.0f);
    text.setPosition(parent.getPosition().x + 20, window.getSize().y / 2);

    window.draw(text);
}

void SpeedInfo::Render(sf::RenderWindow& window)
{
    window.draw(text);
}

void SpeedInfo::Update(float speed)
{
    text.setString(std::to_wstring((int)std::round(speed / 4)) + L" κμ/χ");
}
