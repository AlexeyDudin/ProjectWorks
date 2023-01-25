#include "CarEnemie.h"
#include "Constants.h"

CarEnemie::CarEnemie()
{
}

CarEnemie::~CarEnemie()
{
}

void CarEnemie::Initialize(sf::RenderWindow& window)
{
    obj.setSize(carSize);
    SetDefaultCarPosition(window);
    carTexture.loadFromFile("C:\\Labs\\ProjectWorks\\Game\\Game\\Resources\\EnemieCar.png");
    carTexture.setSmooth(true);
    obj.setTexture(&carTexture, false);
    window.draw(obj);
}

void CarEnemie::Update(sf::Event event, float time)
{

}

void CarEnemie::Render(sf::RenderWindow& window)
{
    window.draw(obj);
}

sf::Vector2f CarEnemie::GetCarPosition()
{
	return obj.getPosition();
}

sf::Vector2f CarEnemie::GetCarSize()
{
	return obj.getSize();
}
