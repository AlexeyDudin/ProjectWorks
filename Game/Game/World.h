#pragma once
#include "Road.h"
#include "Car.h"
#include "Information.h"
#include "LevelGenerator.h"

class World
{
private:
	Road* road;
	Car* car;
	Information* info;
	LevelGenerator* level;
public:
	World();
	~World();

	void Initialize(sf::RenderWindow& window);
	void Update(sf::Event event, float time, float timer);
	void Render(sf::RenderWindow& window);
};