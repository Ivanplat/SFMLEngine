#include "pch.h"
#include "Actor.h"

AActor::AActor() noexcept
{
	IsDrawable_ = true;
	ForwardVector_ = sf::Vector2f(1.0f, 0.0f);
	RightVector_ = sf::Vector2f(0.0f, -1.0f);
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

sf::Vector2f& AActor::GetActorForwardVector()
{
	return ForwardVector_;
}

sf::Vector2f& AActor::GetActorRightVector()
{
	return RightVector_;
}

void AActor::SetOwner(SObject* NewOwner)
{
	Owner_ = NewOwner;
}

SObject* AActor::GetOwner() const
{
	return Owner_;
}
