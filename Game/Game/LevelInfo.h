#pragma once
#include <SFML/Graphics.hpp>

class LevelInfo
{
private:
	sf::Font font;
	sf::Text text;

public:
	LevelInfo();
	~LevelInfo();

	void Initialize(sf::RenderWindow& window, sf::RectangleShape parent, int level);
	void Render(sf::RenderWindow& window);
};