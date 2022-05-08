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
	AActor::AActor();
	CircleShape_ = new sf::CircleShape();
	CircleShape_->setRadius(Size_);
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
