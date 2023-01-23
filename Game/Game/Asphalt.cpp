#include "Asphalt.h"
#include "Constants.h"

Asphalt::Asphalt()
{
}

Asphalt::~Asphalt()
{
}

void Asphalt::Initialize(sf::RenderWindow& window, unsigned int ROAD_WIDTH)
{
	sf::Vector2f size = { (float)ROAD_WIDTH, (float)window.getSize().y };
	obj.setFillColor(asphaltColor);
	obj.setSize(size);
	obj.setPosition({ (float)(window.getSize().x / 2 - ROAD_WIDTH / 2), (float)0 });
	window.draw(obj);
}

void Asphalt::Update()
{
}

void Asphalt::Render(sf::RenderWindow& window)
{
	window.draw(obj);
}

sf::Vector2f Asphalt::GetAsphaltPosition()
{
	return obj.getPosition();
}
