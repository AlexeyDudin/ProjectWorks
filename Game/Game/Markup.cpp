#include "Markup.h"
#include "Constants.h"

Markup::Markup()
{
}

Markup::~Markup()
{
}

void Markup::Initialize(sf::RenderWindow& window, sf::Vector2f position)
{
	obj.setFillColor(markupColor);
	obj.setPosition(position);
	obj.setSize(markupSize);

	windowHeight = window.getSize().y;
	window.draw(obj);
}

void Markup::Update(float speed, float time)
{
	sf::Vector2f position = obj.getPosition();
	position.y += speed * time;
	if (position.y > windowHeight)
		position.y = 0 - markupSize.y;
	obj.setPosition(position);
}

void Markup::Render(sf::RenderWindow& window)
{
	window.draw(obj);
}

int Markup::GetMarkupHeight()
{
	return markupSize.y;
}
