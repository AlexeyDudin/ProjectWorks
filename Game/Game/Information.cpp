#include "Information.h"
#include "Constants.h"

Information::Information()
{
}

Information::~Information()
{
}

void Information::Initialize(sf::RenderWindow& window, LevelGenerator lg)
{
	obj.setFillColor(sf::Color::Black);
	sf::Vector2f tmp = sf::Vector2f(window.getSize().x - (int)INFORMATION_WIDTH, 0);
	obj.setPosition(tmp);
	tmp = sf::Vector2f((int)INFORMATION_WIDTH, window.getSize().y);
	obj.setSize(tmp);
	speedInfo = new SpeedInfo();
	speedInfo->Initialize(window, obj, 0);
	timerInfo = new TimerInfo();
	timerInfo->Initialize(window, obj, 100);
	level = new LevelInfo();
	level->Initialize(window, obj, lg.GetLevel());
	distantionInfo = new DistantionInfo();
	distantionInfo->Initialize(window, obj, lg.GetDistantion());
	window.draw(obj);
}

void Information::Render(sf::RenderWindow& window)
{
	window.draw(obj);
	speedInfo->Render(window);
	timerInfo->Render(window);
	level->Render(window);
	distantionInfo->Render(window);
}

void Information::UpdateSpeed(float speed)
{
	speedInfo->Update(speed);
}

void Information::UpdateTimer(float time)
{
	timerInfo->Update((int)time);
}

void Information::UpdateDistantion(long distantion)
{
	distantionInfo->Update(distantion);
}
