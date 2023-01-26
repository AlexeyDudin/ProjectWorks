#pragma once
#include "Road.h"
#include "Car.h"
#include "Information.h"
#include "LevelGenerator.h"
#include "CarEngine.h"
#include "Level.h"
#include "EnemieGenerator.h"

class World
{
private:
	Road* road;
	Car* car;
	Information* info;
	LevelGenerator* level;
	CarEngineSound* carEngineSound;
	LevelSound* levelSound;
	EnemieGenerator* enemieGenerator;
	void CheckCarCollision();
public:
	World();
	~World();

	bool isLevelComplete = false;
	bool isGameOver = false;
	void Initialize(sf::RenderWindow& window);
	void Update(sf::Event event, float time, float timer);
	void Render(sf::RenderWindow& window);
	void IncrementLevel();
	void EnableSound();
	void DisableSound();
	void ResetLevel();
	void CheckTimer(float timer);
};