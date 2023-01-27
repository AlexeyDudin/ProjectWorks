#include "LevelGenerator.h"
#include "EnemieGenerator.h"

LevelGenerator::LevelGenerator()
{
}

LevelGenerator::~LevelGenerator()
{
}

void LevelGenerator::Initialize()
{
	ResetToDefault();
}

void LevelGenerator::LevelUp(void *enemieGenerator)
{
	enemieGenerator;
	currentLevel++;
	if (currentLevel % 5 == 0)
	{
		timeToEnd -= 10;
		distantion -= 50000;
	}
	else
	{
		distantion += 10000;
	}
	if (currentLevel % 7 == 0)
	{
		((EnemieGenerator*)enemieGenerator)->IncrementCountOfenemies();
	}
	runnedDistantion = distantion;
}

int LevelGenerator::GetTimeToEnd()
{
	return timeToEnd;
}

void LevelGenerator::ResetToDefault()
{
	currentLevel = 1;
	timeToEnd = 100;
	distantion = 40000;
	runnedDistantion = distantion;
}

long LevelGenerator::GetDistantion()
{
	return runnedDistantion;
}

int LevelGenerator::GetLevel()
{
	return currentLevel;
}

void LevelGenerator::UpdateDistantion(float speed, float deltaTime)
{
	runnedDistantion -= speed * deltaTime;
}
