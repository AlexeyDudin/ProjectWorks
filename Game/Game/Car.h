#pragma once
#include <SFML/Graphics.hpp>
#include "iostream"

class Car 
{
private:
	void MoveLeft(float time);
	void MoveRight(float time);
	sf::RectangleShape obj;
	sf::Texture carTexture;
public:
	Car();
	~Car();

	void Initialize(sf::RenderWindow& window);
	void Update(sf::Event event, float time);
	void Render(sf::RenderWindow& window);
	sf::Vector2f GetCarPosition();
	sf::Vector2f GetCarSize();
};