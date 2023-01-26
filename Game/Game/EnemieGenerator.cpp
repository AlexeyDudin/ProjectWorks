#include "EnemieGenerator.h"

EnemieGenerator::EnemieGenerator()
{
}

EnemieGenerator::~EnemieGenerator()
{
}

void EnemieGenerator::Initialize(sf::RenderWindow& window)
{
	local = &window;
	countOfEnemies = 2;
}

void EnemieGenerator::CheckEnemiesIsOut()
{
	vector<CarEnemie*>::iterator it = carEnemies.begin();
	
	while (it < carEnemies.end())
	{
		if ((*it)->IsOutOfRoad())
		{
			delete((*it));
			carEnemies.erase(it);
			it = carEnemies.begin();
		}
		else if (carEnemies.size() > 0)
			it++;
		else
			break;
	}
}

void EnemieGenerator::Update(float speed, float timer)
{
	int random_variable = std::rand() % 2;
	if (random_variable <= 1)
	{
		if (carEnemies.size() < countOfEnemies)
		{
			CarEnemie* enemie = new CarEnemie();
			enemie->Initialize(*local);
			carEnemies.push_back(enemie);
		}
	}
	for (int i = 0; i < carEnemies.size(); i++)
	{
		carEnemies[i]->Update(speed, timer);
	}
	CheckEnemiesIsOut();
}

void EnemieGenerator::Render(sf::RenderWindow& window)
{
	for (int i = 0; i < carEnemies.size(); i++)
	{
		carEnemies[i]->Render(window);
	}
}

void EnemieGenerator::IncrementCountOfenemies()
{
	countOfEnemies++;
}

vector<CarEnemie*> EnemieGenerator::GetCarEnemies()
{
	return carEnemies;
}

void EnemieGenerator::CleanEnemies()
{
	while (carEnemies.size() > 0)
	{
		delete(carEnemies[carEnemies.size() - 1]);
		carEnemies.pop_back();
	}
}
