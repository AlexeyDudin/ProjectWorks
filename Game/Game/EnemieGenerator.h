#pragma once
#include <SFML/Graphics.hpp>
#include "CarEnemie.h"
#include <vector>
#include "HealerCarEnemie.h"

using namespace std;

class EnemieGenerator
{
private:
	vector<CarEnemie*> carEnemies;
	HealerCarEnemie* healerCar;
	int countOfEnemies;
	sf::RenderWindow* local;
	bool IsHaveCollision(CarInterface* currentCar);
public:
	EnemieGenerator();
	~EnemieGenerator();

	void Initialize(sf::RenderWindow& window);
	void Update(float speed, float timer);
	void Render(sf::RenderWindow& window);
	void IncrementCountOfenemies();
	vector<CarEnemie*> GetCarEnemies();
	HealerCarEnemie* GetHealerCar();
	void CleanEnemies();
	void CheckEnemiesIsOut();
	void DestroyHealerCar();
};