#pragma once
#include <SFML/Graphics.hpp>
#include "SpeedInfo.h"
#include "TimerInfo.h"

class Information
{
private:
	sf::RectangleShape obj;
	SpeedInfo* speedInfo;
	TimerInfo* timerInfo;
	
public:
	Information();
	~Information();

	void Initialize(sf::RenderWindow& window);
	void Render(sf::RenderWindow& window);
	void UpdateSpeed(float speed);
	void UpdateTimer(float time);
};