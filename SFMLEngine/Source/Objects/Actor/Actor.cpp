#include "pch.h"
#include "Actor.h"

AActor::AActor() noexcept
{
	IsDrawable_ = true;
}

sf::Shape* AActor::GetDrawablePart()
{
	return nullptr;
}

void AActor::Initialize()
{
	if (auto* dp = GetDrawablePart())
	{
		dp->setFillColor(Color_);
		dp->setPosition(Position_);
		if (auto circle = dynamic_cast<sf::CircleShape*>(dp))
		{
			circle->setRadius(Size_);
		}
	}
}
