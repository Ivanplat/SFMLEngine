#pragma once
#include "Objects/Actor/Actor.h"

class APawn;

class AController : virtual public AActor
{
public:
	explicit AController();
public:
	virtual void AddMovementInput(sf::Vector2f Direction, const float Value);
	virtual void Posses(APawn* Pawn);
private:
	APawn* ControlledPawn_;
};
