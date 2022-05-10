#pragma once

#include "Objects/Actor/Actor.h"
#include "SFML/Graphics.hpp"

class ATestActor : public AActor
{
public:
	explicit ATestActor(sf::Color& Color, const float Radius, sf::Vector2f& Position);
	explicit ATestActor();
	virtual ~ATestActor();
	virtual sf::Shape* GetDrawablePart() override;
private:
	sf::CircleShape* CircleShape_;
};