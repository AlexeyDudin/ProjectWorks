#include "CarEnemie.h"
//#include "Constants.h"
#include <iostream>

void CarEnemie::MoveLeft(float time)
{
    sf::Vector2f currPos = obj.getPosition();
    //std::cout << "Before " << currPos.x << " " << currPos.y << std::endl;
    currPos.x -= time * enemieMove;
    if (currPos.x < MIN_AVAILABLE_CAR_POSITION)
        currPos.x = MIN_AVAILABLE_CAR_POSITION;
    //std::cout << "After " << currPos.x << " " << currPos.y << std::endl;
    obj.setPosition(currPos);
}

void CarEnemie::MoveRight(float time)
{
    sf::Vector2f currPos = obj.getPosition();
    //std::cout << "Before " << currPos.x << " " << currPos.y << std::endl;
    currPos.x += time * enemieMove;
    if (currPos.x + obj.getSize().x > MAX_AVAILABLE_CAR_POSITION)
        currPos.x = MAX_AVAILABLE_CAR_POSITION - obj.getSize().x;
    //std::cout << "After " << currPos.x << " " << currPos.y << std::endl;
    obj.setPosition(currPos);
}

CarEnemie::CarEnemie()
{
}

CarEnemie::~CarEnemie()
{
}

float GenerateRandomPosition()
{
    int MIN_POSITION = (WINDOW_WIDTH / 2) - (ROAD_WIDTH / 2);
    int MAX_POSITION = (WINDOW_WIDTH / 2) + (ROAD_WIDTH / 2) - carSize.x;
    int random_variable = MIN_POSITION + std::rand() % ROAD_WIDTH;
    if (random_variable > MAX_POSITION)
    {
        random_variable -= carSize.x;
    }
    return (float)random_variable;
}

void CarEnemie::Initialize(sf::RenderWindow& window)
{
    obj.setSize(carSize);
    level = (EnemieLevel)(std::rand() % 3);
    carTexture.loadFromFile("C:\\Labs\\ProjectWorks\\Game\\Game\\Resources\\EnemieCar.png");
    carTexture.setSmooth(true);
    obj.setTexture(&carTexture, false);
    obj.setPosition({ GenerateRandomPosition(), -carSize.y });
    window.draw(obj);
}

void CarEnemie::ReInitStartPosition()
{
    obj.setPosition({ GenerateRandomPosition(), -carSize.y });
}

void CarEnemie::Update(float roadSpeed, float time)
{
    sf::Vector2f pos = obj.getPosition();
    pos.y += (roadSpeed - speed) * time;
    obj.setPosition(pos);
    switch (level)
    {
        case profi:
        {

            break;
        }
        case middle:
        {
            int MIN_POSITION = (WINDOW_WIDTH / 2) - (ROAD_WIDTH / 2);
            int MAX_POSITION = (WINDOW_WIDTH / 2) + (ROAD_WIDTH / 2) - carSize.x;
            carMove = (CarMove)(std::rand() % 2);
            if (carMove == turnRight)
            {
                std::cout << obj.getPosition().x << ":" << MAX_POSITION << std::endl;
            }
            if (obj.getPosition().x <= MIN_POSITION)
            {
                carMove = turnRight;
            }
            if (obj.getPosition().x >= MAX_POSITION)
            {
                carMove = turnLeft;
            }
            if (carMove == turnLeft)
            {
                MoveLeft(time);
            }
            else if (carMove == turnRight)
            {
                MoveRight(time);
            }
            break;
        }
        case newbee:
        {
            break;
        }
    }
}

void CarEnemie::Render(sf::RenderWindow& window)
{
    window.draw(obj);
}

sf::Vector2f CarEnemie::GetCarPosition()
{
	return obj.getPosition();
}

sf::Vector2f CarEnemie::GetCarSize()
{
	return obj.getSize();
}

bool CarEnemie::IsOutOfRoad()
{
    sf::Vector2f position = obj.getPosition();
    return position.y >= WINDOW_HEIGHT;
}
