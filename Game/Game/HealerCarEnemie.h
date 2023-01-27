#pragma once
#include <SFML/Graphics.hpp>
#include "CarInterface.h"

class HealerCarEnemie: public CarInterface
{
public:
	HealerCarEnemie();
	~HealerCarEnemie();

	void Initialize(sf::RenderWindow& window);
	void ReInitStartPosition();
	void Update(float roadSpeed, float time);
	void Render(sf::RenderWindow& window);
	sf::Vector2f GetCarPosition();
	sf::Vector2f GetCarSize();
	bool IsOutOfRoad();
};