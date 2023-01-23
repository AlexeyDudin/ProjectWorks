#include "LevelGenerator.h"

LevelGenerator::LevelGenerator()
{
}

LevelGenerator::~LevelGenerator()
{
}

void LevelGenerator::Initialize()
{
	currentLevel = 1;
	timeToEnd = 100;
	distantion = 100000;
}

void LevelGenerator::LevelUp()
{
	currentLevel++;
	if (currentLevel % 5 == 0)
	{
		timeToEnd -= 10;
		distantion -= 10000;
	}
	else
	{
		distantion += 20000;
	}
}

int LevelGenerator::GetTimeToEnd()
{
	return timeToEnd;
}

long LevelGenerator::GetDistantion()
{
	return distantion;
}

int LevelGenerator::GetLevel()
{
	return currentLevel;
}

void LevelGenerator::UpdateDistantion(float speed, float deltaTime)
{
	distantion -= speed * deltaTime;
}
