#pragma once
#include <SFML/Graphics.hpp>

class Asphalt
{
private:
	sf::RectangleShape obj;
public:
	Asphalt();
	~Asphalt();
	void Initialize(sf::RenderWindow& window, unsigned int ROAD_WIDTH);
	void Update();
	void Render(sf::RenderWindow& window);
	sf::Vector2f GetAsphaltPosition();
};