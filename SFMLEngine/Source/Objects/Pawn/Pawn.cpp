#include "pch.h"
#include "Pawn.h"

void APawn::SetupInputComponent(SInputComponent* InputComponent)
{
	if (!InputComponent)
	{
		auto ctr = GetController<AController>();
		InputComponent = GetController<AController>()->GetInputComponent();
	}
	if (!InputComponent)
	{
		throw std::exception("NO INPUT COMPONENT!");
	}
}

void APawn::BeginStart()
{
	AActor::BeginStart();
}
