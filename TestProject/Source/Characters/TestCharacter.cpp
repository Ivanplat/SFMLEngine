#include "TestCharacter.h"

ATestChracter::ATestChracter()
{
	ACharacter::ACharacter();
	CircleShape_ = new sf::CircleShape();
}

sf::Shape* ATestChracter::GetDrawablePart()
{
	return CircleShape_;
}

void ATestChracter::SetupInputComponent(SInputComponent* InputComponent)
{
	ACharacter::SetupInputComponent(InputComponent);
	void(ATestChracter::* Event)();
	InputComponent->BindActionEvent(sf::Keyboard::W, this, "MoveForward", EKeyEventType::Pressed, &ATestChracter::MoveForward);
}

void ATestChracter::MoveForward()
{
	auto Controller = GetController<AController>();
	Controller->AddMovementInput(sf::Vector2f(1.0f, 0.0f), 1.0f);
}
