#include "Road.h"
#include "Constants.h"

float speed = 0;

Road::Road()
{
}

Road::~Road()
{
	asphalt->~Asphalt();
	for (int i = 0; i < markups.size(); i++)
	{
		markups[i]->~Markup();
	}
}

void Road::Initialize(sf::RenderWindow& window)
{
	asphalt = new Asphalt();
	asphalt->Initialize(window, ROAD_WIDTH);
	ResetMarkups(window);
}

void Road::SpeedUp(float dt)
{
	if (speed < speedLimit)
	{
		speed += dt * deltaSpeed;
		if (speed > speedLimit)
		{
			speed = speedLimit;
		}
	}
}

void Road::SpeedDown(float dt)
{
	if (speed > 0)
	{
		speed -= dt * deltaSpeed;
		if (speed < 0)
		{
			speed = 0;
		}
	}
}

void Road::UpdateMarkups(float time)
{
	if (canMove)
	{
		for (int i = 0; i < markups.size(); i++)
		{
			markups[i]->Update(speed, time);
		}
	}
}

void Road::AutoBreak(float time)
{
	if (speed > 0)
		speed -= breakSpeed * time;
}

void Road::Update(sf::Event event, float time)
{
	AutoBreak(time);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		SpeedUp(time);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		SpeedDown(time);
	}

	UpdateMarkups(time);
}

void Road::Render(sf::RenderWindow& window)
{
	asphalt->Render(window);
	for (int i = 0; i < markupCount; i++)
	{
		markups[i]->Render(window);
	}
}

void Road::CheckCarPosition(Car car, float deltaTime)
{
	sf::Vector2f carPosition = car.GetCarPosition();
	sf::Vector2f carSize = car.GetCarSize();
	if (carPosition.x < asphalt->GetAsphaltPosition().x || carPosition.x + carSize.x > asphalt->GetAsphaltPosition().x + ROAD_WIDTH)
	{
		if (speed > speedLimitUnderRoad)
		{
			speed -= breakSpeed * 4 * deltaTime;
		}
	}
}

float Road::GetSpeed()
{
	return speed;
}

void Road::CanMove(bool state)
{
	canMove = state;
}

void Road::ResetSpeed()
{
	speed = 0;
}

void Road::ResetMarkups(sf::RenderWindow& window)
{
	while (markups.size() > 0)
	{
		delete(markups[markups.size() - 1]);
		markups.pop_back();
	}
	int startPosition = 0;
	for (int i = 0; i < markupCount; i++)
	{
		Markup* markup = new Markup();
		startPosition = i * (window.getSize().y + markupSize.y) / markupCount;
		markup->Initialize(window, { (float)(window.getSize().x / 2), (float)startPosition });
		markups.push_back(markup);
	}
}

void Road::CollisionEvent(RoadMove roadMove)
{
	if (roadMove == speedUp)
	{
		SpeedUp(1.0f);
	}
	else if (roadMove == speedDown)
	{
		SpeedDown(1.0f);
	}
}
