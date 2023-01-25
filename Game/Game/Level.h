#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#define NSAMPLES 44100

class LevelSound
{
private:
	sf::SoundBuffer buffer;
	sf::Sound sound;

	sf::Int16 samples[NSAMPLES];
public:
	LevelSound();
	~LevelSound();

	void Initialize();
	void PlayEndLevelSound();
	void PlayDieSound();
};