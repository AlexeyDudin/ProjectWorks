#pragma once

class LevelGenerator
{
private:
	int timeToEnd;
	long distantion;
	int currentLevel;

public:
	LevelGenerator();
	~LevelGenerator();

	void Initialize();
	void LevelUp();
	int GetTimeToEnd();
	long GetDistantion();
	int GetLevel();
	void UpdateDistantion(float speed, float deltaTime);
};