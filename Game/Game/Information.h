#pragma once
#include <SFML/Graphics.hpp>
#include "SpeedInfo.h"
#include "TimerInfo.h"
#include "LevelInfo.h"
#include "LevelGenerator.h"
#include "DistantionInfo.h"
#include "HealthInfo.h"

class Information
{
private:
	sf::RectangleShape obj;
	SpeedInfo* speedInfo;
	TimerInfo* timerInfo;
	LevelInfo* level;
	DistantionInfo* distantionInfo;
	HealthInfo* healthInfo;
	
public:
	Information();
	~Information();

	void Initialize(sf::RenderWindow& window, LevelGenerator lg);
	void Render(sf::RenderWindow& window);
	void UpdateSpeed(float speed);
	void UpdateTimer(float time);
	void UpdateDistantion(long distantion);
	void UpdateLevel(int level);
	void UpdateHealth(unsigned int health);
};