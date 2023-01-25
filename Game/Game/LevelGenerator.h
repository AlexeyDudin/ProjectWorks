#pragma once

class LevelGenerator
{
private:
	int timeToEnd;
	long distantion;
	int currentLevel;
	int runnedDistantion;

public:
	LevelGenerator();
	~LevelGenerator();

	void Initialize();
	void LevelUp();
	int GetTimeToEnd();
	void ResetToDefault();
	long GetDistantion();
	int GetLevel();
	void UpdateDistantion(float speed, float deltaTime);
};