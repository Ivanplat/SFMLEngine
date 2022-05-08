#include "pch.h"
#include "Actor.h"

AActor::AActor() noexcept
{
	IsDrowable_ = true;

	if (auto dp = GetDrawablePart())
	{
		dp->setFillColor(Color_);
		dp->setPosition(Position_);
	}
}

sf::Shape* AActor::GetDrawablePart()
{
	return nullptr;
}
