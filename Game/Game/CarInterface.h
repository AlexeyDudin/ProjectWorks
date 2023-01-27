#pragma once
#include <SFML/Graphics.hpp>

class CarInterface 
{
	protected:
		sf::RectangleShape obj;
		sf::Texture carTexture;
		float speed = 900.0f;
	public:
		virtual void Initialize(sf::RenderWindow& window) = NULL;
		virtual void ReInitStartPosition() = NULL;
		virtual void Update(float roadSpeed, float time) = NULL;
		virtual void Render(sf::RenderWindow& window) = NULL;
		virtual sf::Vector2f GetCarPosition() = 0;
		virtual sf::Vector2f GetCarSize() = 0;
		virtual bool IsOutOfRoad() = 0;
};