#pragma once
#include <SFML/Graphics.hpp>

class Markup
{
private:
	sf::RectangleShape obj;
	int windowHeight;
public:
	Markup();
	~Markup();
	void Initialize(sf::RenderWindow& window, sf::Vector2f position);
	void Update(float speed, float time);
	void Render(sf::RenderWindow& window);
	int GetMarkupHeight();
};