#include <SFML/Graphics.hpp>
#include <cmath>
#include "EyeEnum.h"
#include <iostream>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

unsigned short quality = 200;
float radius_x = 30;
float radius_y = 80;
sf::Vector2f centerLeftEye = {250, 300};
sf::Vector2f centerRightEye = { 450, 300 };
sf::Vector2f maxMoving = { 30, 30 };

struct Eye
{
	sf::ConvexShape whiteSpace;
	sf::ConvexShape blackSpace;
};

sf::Vector2f toEuclidean(float radius, float angle)
{
	return {
		radius * cos(angle),
		radius * sin(angle) };
}

float toDegres(float radians)
{
	return float(double(radians) * 180.0 / M_PI);
}

void initializeEye(Eye& eye, eyePosition position)
{
	eye.whiteSpace.setPointCount(quality);
	eye.blackSpace.setPointCount(quality);
	for (unsigned short i = 0; i < quality; ++i)
	{
		float rad = (360 / quality * i) / (360 / M_PI / 4);
		//float x = cos(rad) * radius_x;
		//float y = sin(rad) * radius_y;

		eye.whiteSpace.setPoint(i, toEuclidean(radius_y, rad));
	}
	for (unsigned short i = 0; i < quality; ++i)
	{
		float rad = (360 / quality * i) / (360 / M_PI / 4);
		eye.blackSpace.setPoint(i, toEuclidean(radius_x, rad));
	}
	eye.whiteSpace.setFillColor(sf::Color(0xff, 0xff, 0xff));
	eye.blackSpace.setFillColor(sf::Color(0x00, 0x00, 0x00));
	if (position == left)
	{
		eye.whiteSpace.setPosition(centerLeftEye);
		eye.blackSpace.setPosition(centerLeftEye);
	}
	else
	{
		eye.whiteSpace.setPosition(centerRightEye);
		eye.blackSpace.setPosition(centerRightEye);
	}

	
}

void onMouseMove(const sf::Event::MouseMoveEvent& event, sf::Vector2f& mousePosition)
{
	std::cout << "mouse x=" << event.x << ", y=" << event.y << std::endl;
	mousePosition = { float(event.x), float(event.y) };
}

void updateEyeElements(Eye& eye, sf::Vector2f& centerEye, sf::Vector2f& mousePosition)
{
	sf::Vector2f tmpPosEye = mousePosition - centerEye;

	sf::Vector2f resultPosition;

	if (abs(tmpPosEye.x) < maxMoving.x)
		resultPosition.x = mousePosition.x;
	else if (tmpPosEye.x < 0)
	{
		resultPosition.x = centerEye.x - maxMoving.x;
	}
	else
	{
		resultPosition.x = centerEye.x + maxMoving.x;
	}

	if (abs(tmpPosEye.y) < maxMoving.y)
		resultPosition.y = mousePosition.y;
	else if (tmpPosEye.y < 0)
	{
		resultPosition.y = centerEye.y - maxMoving.y;
	}
	else
		resultPosition.y = centerEye.y + maxMoving.y;

	eye.blackSpace.setPosition(resultPosition);
	//eye.blackSpace.setPosition();
	/*const sf::Vector2f headOffset = toEuclidean(40, eye.rotation);
	arrow.head.setPosition(arrow.position + headOffset);
	arrow.head.setRotation(toDegres(arrow.rotation));

	const sf::Vector2f stemOffset = toEuclidean(-10, arrow.rotation);
	arrow.stem.setPosition(arrow.position);
	arrow.stem.setRotation(toDegres(arrow.rotation));*/
}

void pollEvents(sf::RenderWindow& window, sf::Vector2f& mousePosition)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window.close();
			break;
		case sf::Event::MouseMoved:
			onMouseMove(event.mouseMove, mousePosition);
			break;
		default:
			break;
		}
	}
}

void update(sf::Vector2f& mousePosition, Eye& eye1, Eye& eye2)
{
	/*const sf::Vector2f delta = mousePosition - eye.blackSpace.getPosition;
	eye.rotation = atan2(delta.y, delta.x);*/
	updateEyeElements(eye1, centerLeftEye, mousePosition);
	updateEyeElements(eye2, centerRightEye, mousePosition);
}

void redrawFrame(sf::RenderWindow& window, Eye& eye1, Eye& eye2)
{
	window.clear();
	window.draw(eye1.whiteSpace);
	window.draw(eye1.blackSpace);

	window.draw(eye2.whiteSpace);
	window.draw(eye2.blackSpace);
	window.display();
}

int main()
{

	constexpr unsigned WINDOW_WIDTH = 800;
	constexpr unsigned WINDOW_HEIGHT = 600;

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(
		sf::VideoMode({ WINDOW_WIDTH, WINDOW_HEIGHT }),
		"Eye follows mouse", sf::Style::Default, settings);


	Eye eye1;
	Eye eye2;
	initializeEye(eye1, left);
	initializeEye(eye2, right);

	sf::Vector2f mousePosition;

	while (window.isOpen())
	{
		pollEvents(window, mousePosition);
		update(mousePosition, eye1, eye2);
		redrawFrame(window, eye1, eye2);
	}
}