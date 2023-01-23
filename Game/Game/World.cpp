#include "World.h"

World::World()
{
}

World::~World()
{
	delete(road);
}

void World::Initialize(sf::RenderWindow& window)
{
	road = new Road();
	road->Initialize(window);
    car = new Car();
    car->Initialize(window);
    info = new Information();
    info->Initialize(window);
}

void World::Update(sf::Event event, float time, float timer)
{
    car->Update(event, time);
    road->CheckCarPosition(*car, time);
    road->Update(event, time);
    info->UpdateSpeed(road->GetSpeed());
    info->UpdateTimer(timer);
}

void World::Render(sf::RenderWindow& window)
{
	road->Render(window);
    car->Render(window);
    info->Render(window);
}
