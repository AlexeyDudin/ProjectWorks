#pragma once
#include <SFML/Graphics.hpp>
#include "SpeedInfo.h"
#include "TimerInfo.h"
#include "LevelInfo.h"
#include "LevelGenerator.h"
#include "DistantionInfo.h"

class Information
{
private:
	sf::RectangleShape obj;
	SpeedInfo* speedInfo;
	TimerInfo* timerInfo;
	LevelInfo* level;
	DistantionInfo* distantionInfo;
	
public:
	Information();
	~Information();

	void Initialize(sf::RenderWindow& window, LevelGenerator lg);
	void Render(sf::RenderWindow& window);
	void UpdateSpeed(float speed);
	void UpdateTimer(float time);
	void UpdateDistantion(long distantion);
};