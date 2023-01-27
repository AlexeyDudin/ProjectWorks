#include "HealerCarEnemie.h"
#include "Constants.h"

HealerCarEnemie::HealerCarEnemie()
{
}

HealerCarEnemie::~HealerCarEnemie()
{
}

extern float GenerateRandomPosition();

void HealerCarEnemie::Initialize(sf::RenderWindow& window)
{
    obj.setSize(carSize);
    carTexture.loadFromFile("C:\\Labs\\ProjectWorks\\Game\\Game\\Resources\\TimerCar.png");
    carTexture.setSmooth(true);
    obj.setTexture(&carTexture, false);
    obj.setPosition({ GenerateRandomPosition(), -carSize.y });
    window.draw(obj);
}

void HealerCarEnemie::ReInitStartPosition()
{
    obj.setPosition({ GenerateRandomPosition(), -carSize.y });
}

void HealerCarEnemie::Update(float roadSpeed, float time)
{
    sf::Vector2f pos = obj.getPosition();
    pos.y += (roadSpeed - speed) * time;
    obj.setPosition(pos);
}

void HealerCarEnemie::Render(sf::RenderWindow& window)
{
    window.draw(obj);
}

sf::Vector2f HealerCarEnemie::GetCarPosition()
{
    return obj.getPosition();
}

sf::Vector2f HealerCarEnemie::GetCarSize()
{
    return obj.getSize();
}

bool HealerCarEnemie::IsOutOfRoad()
{
    sf::Vector2f position = obj.getPosition();
    return position.y >= WINDOW_HEIGHT;
}
