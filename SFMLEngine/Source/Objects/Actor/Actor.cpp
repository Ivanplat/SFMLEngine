#include "pch.h"
#include "Actor.h"

AActor::AActor() noexcept
{
	IsDrowable_ = true;
}

sf::Shape* AActor::GetDrawablePart()
{
	return nullptr;
}
