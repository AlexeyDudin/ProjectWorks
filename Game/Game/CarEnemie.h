#pragma once
#include "CarInterface.h"
#include "Constants.h"

class CarEnemie: public CarInterface
{
private:
	void MoveLeft(float time);
	void MoveRight(float time);
	EnemieLevel level;
	CarMove carMove;
public:
	CarEnemie();
	~CarEnemie();

	void Initialize(sf::RenderWindow& window);
	void ReInitStartPosition();
	void Update(float roadSpeed, float time);
	void Render(sf::RenderWindow& window);
	sf::Vector2f GetCarPosition();
	sf::Vector2f GetCarSize();
	bool IsOutOfRoad();
};