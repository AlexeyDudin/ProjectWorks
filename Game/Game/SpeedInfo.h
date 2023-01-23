#pragma once
#include <SFML/Graphics.hpp>

class SpeedInfo
{
private:
	sf::Text text;
	sf::Font font;

public:
	SpeedInfo();
	~SpeedInfo();

	void Initialize(sf::RenderWindow& window, sf::RectangleShape parent, float speed);
	void Render(sf::RenderWindow& window);
	void Update(float speed);
};