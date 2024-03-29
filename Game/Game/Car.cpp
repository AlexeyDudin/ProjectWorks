#include "Car.h"

void Car::MoveLeft(float time)
{
    sf::Vector2f currPos = obj.getPosition();
    //std::cout << "Before " << currPos.x << " " << currPos.y << std::endl;
    currPos.x -= time * carMove;
    if (currPos.x < MIN_AVAILABLE_CAR_POSITION)
        currPos.x = MIN_AVAILABLE_CAR_POSITION;
    //std::cout << "After " << currPos.x << " " << currPos.y << std::endl;
    obj.setPosition(currPos);

    //std::cout << "Saved " << obj.getPosition().x << " " << obj.getPosition().y << std::endl;
}

void Car::MoveRight(float time)
{
    sf::Vector2f currPos = obj.getPosition();
    //std::cout << "Before " << currPos.x << " " << currPos.y << std::endl;
    currPos.x += time * carMove;
    if (currPos.x + obj.getSize().x > MAX_AVAILABLE_CAR_POSITION)
        currPos.x = MAX_AVAILABLE_CAR_POSITION - obj.getSize().x;
    //std::cout << "After " << currPos.x << " " << currPos.y << std::endl;
    obj.setPosition(currPos);

    //std::cout << "Saved " << obj.getPosition().x << " " << obj.getPosition().y << std::endl;
}

Car::Car()
{
}

Car::~Car()
{
}

void Car::Initialize(sf::RenderWindow& window)
{
    health = 100;
    //obj.setFillColor(carColor);
    obj.setSize(carSize);
    SetDefaultCarPosition(window);
    carTexture.loadFromFile("C:\\Labs\\ProjectWorks\\Game\\Game\\Resources\\MainCar.png");
    carTexture.setSmooth(true);
    obj.setTexture(&carTexture, false);
    window.draw(obj);
}

void Car::Update(sf::Event event, float time)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        MoveLeft(time);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        MoveRight(time);
    }
}

void Car::Render(sf::RenderWindow& window)
{
    window.draw(obj);
}

sf::Vector2f Car::GetCarPosition()
{
    return obj.getPosition();
}

sf::Vector2f Car::GetCarSize()
{
    return obj.getSize();
}

void Car::MoveUp(float speed, float deltaTime)
{
    sf::Vector2f currPos = obj.getPosition();
    currPos.y -= speed * deltaTime;
    if (currPos.y < -obj.getSize().y)
        currPos.y = -obj.getSize().y;
    obj.setPosition(currPos);
}

void Car::SetDefaultCarPosition(sf::RenderWindow& window)
{
    sf::Vector2f position = { (float)(window.getSize().x / 2), (float)(window.getSize().y - carSize.y) };
    obj.setPosition(position);
}

void Car::CollisionEvent(CarMove carMove)
{
    health -= 20;
    if (carMove == turnLeft)
    {
        MoveLeft(0.2f);
    }
    else if (carMove == turnRight)
    {
        MoveRight(0.2f);
    }
}

bool Car::IsHealthEnd()
{
    return (health == 0);
}

unsigned int Car::GetHealth()
{
    return health;
}

void Car::ResetHealth()
{
    health = 100;
}

void Car::IncrementHealth()
{
    health += 20;
    if (health > 100)
        health = 100;
}
