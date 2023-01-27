#include "World.h"
#include "Constants.h"

bool InRange(float min, float max, float pos)
{
    return (min <= pos && pos <= max);
}

void World::CheckCarCollision()
{
    vector<CarEnemie*> enemies = enemieGenerator->GetCarEnemies();
    sf::Vector2f mainCarPosition = car->GetCarPosition();

    std::srand(std::time(nullptr));
    for (int i = 0; i < enemies.size(); i++)
    {
        sf::Vector2f enemieCarPosition = enemies[i]->GetCarPosition();
        int carX1 = mainCarPosition.x;
        int carX2 = mainCarPosition.x + carSize.x;
        int carY1 = mainCarPosition.y;
        int carY2 = mainCarPosition.y + carSize.y;
        if ( ((carX2 >= enemieCarPosition.x && carX2 <= enemieCarPosition.x + carSize.x) && 
              (carY2 >= enemieCarPosition.y && carY2 <= enemieCarPosition.y + carSize.y)) ||
             ((carX1 <= enemieCarPosition.x + carSize.x && carX1 >= enemieCarPosition.x) &&
              (carY1 <= enemieCarPosition.y + carSize.y && carY1 >= enemieCarPosition.y))
           )
        {
            if (InRange(enemieCarPosition.x, enemieCarPosition.x + carSize.x, carX2))
            {
                car->CollisionEvent(turnLeft);
            }
            else if (InRange(enemieCarPosition.x, enemieCarPosition.x + carSize.x, carX1))
            {
                car->CollisionEvent(turnRight);
            }
            if (InRange(enemieCarPosition.y, enemieCarPosition.y + carSize.y, carY1))
            {
                road->CollisionEvent(speedDown);
            }
            else if (InRange(enemieCarPosition.y, enemieCarPosition.y + carSize.y, carY2))
            {
                road->CollisionEvent(speedDown);
            }
        }
    }
}

void World::CheckCarHealerCollision(float& timer)
{
    HealerCarEnemie* healerCar = enemieGenerator->GetHealerCar();
    sf::Vector2f mainCarPosition = car->GetCarPosition();

    if (healerCar != NULL)
    {
        sf::Vector2f enemieCarPosition = healerCar->GetCarPosition();
        int carX1 = mainCarPosition.x;
        int carX2 = mainCarPosition.x + carSize.x;
        int carY1 = mainCarPosition.y;
        int carY2 = mainCarPosition.y + carSize.y;
        if (((carX2 >= enemieCarPosition.x && carX2 <= enemieCarPosition.x + carSize.x) &&
            (carY2 >= enemieCarPosition.y && carY2 <= enemieCarPosition.y + carSize.y)) ||
            ((carX1 <= enemieCarPosition.x + carSize.x && carX1 >= enemieCarPosition.x) &&
                (carY1 <= enemieCarPosition.y + carSize.y && carY1 >= enemieCarPosition.y))
            )
        {
            if (InRange(enemieCarPosition.x, enemieCarPosition.x + carSize.x, carX2) || 
                InRange(enemieCarPosition.x, enemieCarPosition.x + carSize.x, carX1) ||
                InRange(enemieCarPosition.y, enemieCarPosition.y + carSize.y, carY1) ||
                InRange(enemieCarPosition.y, enemieCarPosition.y + carSize.y, carY2))
            {
                timer -= 10;
                car->IncrementHealth();
                enemieGenerator->DestroyHealerCar();
            }
        }
    }
}

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

    enemieGenerator = new EnemieGenerator();
    enemieGenerator->Initialize(window);
}

void World::Update(sf::Event event, float time, float &timer)
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

    enemieGenerator->Update(road->GetSpeed(), time);
    CheckCarCollision();
    CheckCarHealerCollision(timer);

    if (car->IsHealthEnd())
    {
        isGameOver = true;
    }

    info->UpdateHealth(car->GetHealth());
}

void World::Render(sf::RenderWindow& window)
{
	road->Render(window);
    car->Render(window);
    info->Render(window);
    enemieGenerator->Render(window);
}

void World::IncrementLevel()
{
    level->LevelUp(enemieGenerator);
    road->ResetSpeed();
    car->SetDefaultCarPosition(*local);
    isLevelComplete = false;
    road->CanMove(true);
    road->ResetMarkups(*local);
    enemieGenerator->CleanEnemies();
    car->ResetHealth();
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
    isGameOver = false;
    road->ResetMarkups(*local);
    enemieGenerator->CleanEnemies();
    car->ResetHealth();
}

void World::CheckTimer(float timer)
{
    if (level->GetTimeToEnd() - (int)timer <= 0)
    {
        isGameOver = true;
    }
}
