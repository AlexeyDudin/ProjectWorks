#pragma once
#include <SFML/Graphics.hpp>

class DistantionInfo
{
private:
	sf::Text text;
	sf::Font font;

public:
	DistantionInfo();
	~DistantionInfo();

	void Initialize(sf::RenderWindow& window, sf::RectangleShape parent, long distantion);
	void Render(sf::RenderWindow& window);
	void Update(long distantion);
};