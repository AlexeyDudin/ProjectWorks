#include "EnemieGenerator.h"
#include "Constants.h"

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

	if (healerCar != NULL)
	{
		if (healerCar->IsOutOfRoad())
		{
			delete(healerCar);
			healerCar = NULL;
		}
	}
}

void EnemieGenerator::DestroyHealerCar()
{
	delete(healerCar);
	healerCar = NULL;
}

bool EnemieGenerator::IsHaveCollision(CarInterface* currentCar)
{
	sf::Vector2f mainCarPosition = currentCar->GetCarPosition();
	for (int i = 0; i < carEnemies.size(); i++)
	{
		sf::Vector2f enemieCarPosition = carEnemies[i]->GetCarPosition();
		int carX1 = mainCarPosition.x;
		int carX2 = mainCarPosition.x + carSize.x;
		int carY1 = mainCarPosition.y;
		int carY2 = mainCarPosition.y + carSize.y;
		if (((carX2 >= enemieCarPosition.x && carX2 <= enemieCarPosition.x + carSize.x) &&
			(carY2 >= enemieCarPosition.y && carY2 <= enemieCarPosition.y + carSize.y)) ||
			((carX1 <= enemieCarPosition.x + carSize.x && carX1 >= enemieCarPosition.x) &&
				(carY1 <= enemieCarPosition.y + carSize.y && carY1 >= enemieCarPosition.y))
			)
		{
			return true;
		}
	}
	if (healerCar != NULL)
	{
		sf::Vector2f enemieCarPosition = healerCar->GetCarPosition();
		int carX1 = mainCarPosition.x;
		int carX2 = mainCarPosition.x + carSize.x;
		int carY1 = mainCarPosition.y;
		int carY2 = mainCarPosition.y + carSize.y;
		if (((carX2 >= enemieCarPosition.x && carX2 <= enemieCarPosition.x + carSize.x) &&
			(carY2 >= enemieCarPosition.y && carY2 <= enemieCarPosition.y + carSize.y)) ||
			((carX1 <= enemieCarPosition.x + carSize.x && carX1 >= enemieCarPosition.x) &&
				(carY1 <= enemieCarPosition.y + carSize.y && carY1 >= enemieCarPosition.y))
			)
		{
			return true;
		}
	}
	return false;
}

void EnemieGenerator::Update(float speed, float timer)
{
	int random_variable = std::rand() % 10;
	if (random_variable <= 2)
	{
		if (carEnemies.size() < countOfEnemies)
		{
			CarEnemie* enemie = new CarEnemie();
			enemie->Initialize(*local);
			while (IsHaveCollision(enemie))
			{
				enemie->ReInitStartPosition();
			}
			carEnemies.push_back(enemie);
		}
	}
	random_variable = std::rand() % 11;
	if (random_variable == 1)
	{
		if (healerCar == NULL)
		{
			HealerCarEnemie* tmp = new HealerCarEnemie();
			tmp->Initialize(*local);
			while (IsHaveCollision(tmp))
			{
				tmp->ReInitStartPosition();
			}
			healerCar = tmp;
		}
	}

	for (int i = 0; i < carEnemies.size(); i++)
	{
		carEnemies[i]->Update(speed, timer);
	}

	if (healerCar != NULL)
	{
		healerCar->Update(speed, timer);
	}

	CheckEnemiesIsOut();

}

void EnemieGenerator::Render(sf::RenderWindow& window)
{
	for (int i = 0; i < carEnemies.size(); i++)
	{
		carEnemies[i]->Render(window);
	}
	if (healerCar != NULL)
	{
		healerCar->Render(window);
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

HealerCarEnemie* EnemieGenerator::GetHealerCar()
{
	return healerCar;
}

void EnemieGenerator::CleanEnemies()
{
	while (carEnemies.size() > 0)
	{
		delete(carEnemies[carEnemies.size() - 1]);
		carEnemies.pop_back();
	}
	if (healerCar != NULL)
	{
		delete(healerCar);
		healerCar = NULL;
	}
}
