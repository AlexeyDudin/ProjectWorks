#pragma once
#include "Car.h"
#include <SFML/Graphics.hpp>

class CarEnemie
{
private:
	/*void MoveLeft(float time);
	void MoveRight(float time);*/
	sf::RectangleShape obj;
	sf::Texture carTexture;
	float speed = 900.0f;
public:
	CarEnemie();
	~CarEnemie();

	void Initialize(sf::RenderWindow& window);
	void Update(float roadSpeed, float time);
	void Render(sf::RenderWindow& window);
	sf::Vector2f GetCarPosition();
	sf::Vector2f GetCarSize();
	bool IsOutOfRoad();
};