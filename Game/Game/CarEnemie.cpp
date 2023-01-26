#include "CarEnemie.h"
#include "Constants.h"

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
    //std::srand(std::time(nullptr)); // use current time as seed for random generator
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
    carTexture.loadFromFile("C:\\Labs\\ProjectWorks\\Game\\Game\\Resources\\EnemieCar.png");
    carTexture.setSmooth(true);
    obj.setTexture(&carTexture, false);
    obj.setPosition({ GenerateRandomPosition(), -carSize.y });
    window.draw(obj);
}

void CarEnemie::Update(float roadSpeed, float time)
{
    sf::Vector2f pos = obj.getPosition();
    pos.y += (roadSpeed - speed) * time;
    obj.setPosition(pos);
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
