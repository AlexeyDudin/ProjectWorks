#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Asphalt.h";
#include "Markup.h"
#include "Car.h"

class Road
{
private:
	Asphalt* asphalt;
	std::vector<Markup> markups;
	void SpeedUp(float dt);
	void SpeedDown(float dt);
	void UpdateMarkups(float time);
	void AutoBreak(float time);
public:
	Road();
	~Road();

	void Initialize(sf::RenderWindow& window);
	void Update(sf::Event event, float time);
	void Render(sf::RenderWindow& window);
	void CheckCarPosition(Car car, float deltaTime);
	float GetSpeed();
};