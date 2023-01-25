#include "World.h"
#include "Constants.h"


World::World()
{
}

World::~World()
{
	delete(road);
}

sf::RenderWindow* local;

void World::Initialize(sf::RenderWindow& window)
{
    local = &window;
	road = new Road();
	road->Initialize(window);
    car = new Car();
    car->Initialize(window);

    info = new Information();

    level = new LevelGenerator();
    level->Initialize();

    info->Initialize(window, *level);

    carEngineSound = new CarEngineSound();
    carEngineSound->Initialize();

    levelSound = new LevelSound();
    levelSound->Initialize();
}

void World::Update(sf::Event event, float time, float timer)
{
    level->UpdateDistantion(road->GetSpeed(), time);
    if (level->GetDistantion() <= (long)WINDOW_HEIGHT)
    {
        car->MoveUp(road->GetSpeed(), time);
        road->CanMove(false);
    }
    if (level->GetDistantion() <= 0)
    {
        //TODO Уровень пройден
        isLevelComplete = true;
        levelSound->PlayEndLevelSound();
    }
    car->Update(event, time);
    road->CheckCarPosition(*car, time);
    road->Update(event, time);
    info->UpdateSpeed(road->GetSpeed());
    info->UpdateLevel(level->GetLevel());
    info->UpdateTimer(level->GetTimeToEnd() - (int)timer);
    info->UpdateDistantion(level->GetDistantion());

    carEngineSound->Update(road->GetSpeed());
    CheckTimer(timer);
}

void World::Render(sf::RenderWindow& window)
{
	road->Render(window);
    car->Render(window);
    info->Render(window);
}

void World::IncrementLevel()
{
    level->LevelUp();
    road->ResetSpeed();
    car->SetDefaultCarPosition(*local);
    isLevelComplete = false;
    road->CanMove(true);
}

void World::EnableSound()
{
    carEngineSound->StartPlay();
}

void World::DisableSound()
{
    carEngineSound->StopPlay();
}

void World::ResetLevel()
{
    level->ResetToDefault();
    levelSound->PlayDieSound();
    road->ResetSpeed();
    car->SetDefaultCarPosition(*local);
}

void World::CheckTimer(float timer)
{
    if (level->GetTimeToEnd() - (int)timer <= 0)
    {
        isGameOver = true;
    }
}
