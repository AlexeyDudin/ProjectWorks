#pragma once
#include <SFML/Graphics.hpp>

const unsigned int WINDOW_HEIGHT = 800;
const unsigned int WINDOW_WIDTH = 800;

const unsigned int ROAD_WIDTH = 300;
const unsigned int markupCount = 5;

const unsigned int MIN_AVAILABLE_CAR_POSITION = (WINDOW_WIDTH / 2) - (ROAD_WIDTH / 2) - 50;
const unsigned int MAX_AVAILABLE_CAR_POSITION = (WINDOW_WIDTH / 2) + (ROAD_WIDTH / 2) + 50;

const float speedLimit = 1600;
const float deltaSpeed = 300;
const float breakSpeed = 150;
const float speedLimitUnderRoad = 600;

const sf::Color markupColor = sf::Color(0xff, 0xff, 0xff);
const sf::Vector2f markupSize = { 20, 50 };

const sf::Color asphaltColor = sf::Color(0x80, 0x80, 0x80);

const sf::Color carColor = sf::Color(0xa0, 0x10, 0x10);
const sf::Vector2f carSize = { 30, 50 };
const int carMove = 200;

const unsigned int INFORMATION_WIDTH = 200;