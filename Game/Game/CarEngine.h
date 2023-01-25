#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <math.h>

#define NSAMPLES 44100

class CarEngineSound
{
private:
	sf::SoundBuffer buffer;
	sf::Sound sound;

	sf::Int16 samples[NSAMPLES];
public:
	CarEngineSound();
	~CarEngineSound();

	void Initialize();
	void Update(float speed);
	void StopPlay();
	void StartPlay();
};