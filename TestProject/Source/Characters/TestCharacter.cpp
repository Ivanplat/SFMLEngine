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
