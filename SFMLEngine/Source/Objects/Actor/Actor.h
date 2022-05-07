#pragma once

#include "Objects/Object/Object.h"
#include "Objects/Class/TSubclassOf.h"

class AActor : public SObject
{
public:
	explicit AActor() noexcept;
	virtual ~AActor() noexcept {};
public:
	virtual sf::Shape* GetDrawablePart();
};