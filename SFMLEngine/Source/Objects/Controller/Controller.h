#pragma once
#include "Objects/Actor/Actor.h"
#include "Objects/ActorComponent/InputComponent.h"

class APawn;

class AController : virtual public AActor
{
public:
	explicit AController();
public:
	virtual void AddMovementInput(sf::Vector2f Direction, const float Value);
	virtual void Posses(APawn* Pawn);
	SInputComponent* GetInputComponent();
private:
	APawn* ControlledPawn_;
	SInputComponent* InputComponent_;
};
