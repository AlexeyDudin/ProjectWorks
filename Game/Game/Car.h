#pragma once
#include <SFML/Graphics.hpp>
#include "iostream"
#include "Constants.h"

class Car 
{
private:
	void MoveLeft(float time);
	void MoveRight(float time);
	sf::RectangleShape obj;
	sf::Texture carTexture;
	unsigned int health;
public:
	Car();
	~Car();

	void Initialize(sf::RenderWindow& window);
	void Update(sf::Event event, float time);
	void Render(sf::RenderWindow& window);
	sf::Vector2f GetCarPosition();
	sf::Vector2f GetCarSize();
	void MoveUp(float speed, float deltaTime);
	void SetDefaultCarPosition(sf::RenderWindow& window);
	void CollisionEvent(CarMove carMove);
	bool IsHealthEnd();
	unsigned int GetHealth();
	void ResetHealth();
};