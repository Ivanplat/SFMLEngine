#include "pch.h"
#include "TestActor.h"


ATestActor::ATestActor(sf::Color& Color, const float Radius, sf::Vector2f& Position)
{
	CircleShape_ = new sf::CircleShape();
	CircleShape_->setFillColor(Color);
	CircleShape_->setRadius(Radius);
	CircleShape_->setPosition(Position);
}

ATestActor::ATestActor()
{
	auto TempColor = sf::Color::Green;
	auto TempPosition = sf::Vector2f(10.0f, 10.0f);
	CircleShape_ = new sf::CircleShape();
	CircleShape_->setFillColor(TempColor);
	CircleShape_->setRadius(10.0f);
	CircleShape_->setPosition(TempPosition);
}

ATestActor::~ATestActor()
{
	if (CircleShape_)
	{
		delete CircleShape_;
	}
}

sf::Shape* ATestActor::GetDrawablePart()
{
	return CircleShape_;
}
