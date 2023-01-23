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

    level = new LevelGenerator();
    level->Initialize();

    info->Initialize(window, *level);
}

void World::Update(sf::Event event, float time, float timer)
{
    level->UpdateDistantion(road->GetSpeed(), time);
    car->Update(event, time);
    road->CheckCarPosition(*car, time);
    road->Update(event, time);
    info->UpdateSpeed(road->GetSpeed());
    info->UpdateTimer(level->GetTimeToEnd() - (int)timer);
    info->UpdateDistantion(level->GetDistantion());
}

void World::Render(sf::RenderWindow& window)
{
	road->Render(window);
    car->Render(window);
    info->Render(window);
}
