#pragma once
#include <SFML/Graphics.hpp>

class TimerInfo
{
private:
	sf::Text text;
	sf::Font font;

public:
	TimerInfo();
	~TimerInfo();

	void Initialize(sf::RenderWindow& window, sf::RectangleShape parent, int time);
	void Render(sf::RenderWindow& window);
	void Update(int time);
};