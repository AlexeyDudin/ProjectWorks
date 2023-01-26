#pragma once
#include <SFML/Graphics.hpp>

class HealthInfo
{
private:
	sf::Font font;
	sf::Text text;

public:
	HealthInfo();
	~HealthInfo();

	void Initialize(sf::RenderWindow& window, sf::RectangleShape parent, unsigned int health);
	void Render(sf::RenderWindow& window);
	void Update(unsigned int health);
};