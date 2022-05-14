#include "pch.h"
#include "Controller.h"
#include "Objects/Pawn/Pawn.h"

AController::AController()
{
	IsDrawable_ = false;
	InputComponent_ = NewObject<SInputComponent>();
}

void AController::AddMovementInput(sf::Vector2f Direction, const float Value)
{
	if (ControlledPawn_)
	{
		if (auto dp = ControlledPawn_->GetDrawablePart())
		{
			auto NewPosition = dp->getPosition() + Direction * Value;
			dp->setPosition(NewPosition);
		}
	}
}

void AController::Posses(APawn* Pawn)
{
	ControlledPawn_ = Pawn;
	ControlledPawn_->SetOwner(this);
	ControlledPawn_->SetupInputComponent(nullptr);
	Engine->SetCurrentPawn(Pawn);
}

SInputComponent* AController::GetInputComponent()
{
	return InputComponent_;
}
