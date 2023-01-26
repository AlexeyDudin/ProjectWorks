#pragma once
#include <SFML/Graphics.hpp>
#include "CarEnemie.h"
#include <vector>

using namespace std;

class EnemieGenerator
{
private:
	vector<CarEnemie*> carEnemies;
	int countOfEnemies;
	sf::RenderWindow* local;
public:
	EnemieGenerator();
	~EnemieGenerator();

	void Initialize(sf::RenderWindow& window);
	void Update(float speed, float timer);
	void Render(sf::RenderWindow& window);
	void IncrementCountOfenemies();
	vector<CarEnemie*> GetCarEnemies();
	void CleanEnemies();
	void CheckEnemiesIsOut();
};