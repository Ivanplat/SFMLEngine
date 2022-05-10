#pragma once

#include "MinimalCore.h"
#include <SFML/Graphics.hpp>

class ATestChracter : public ACharacter
{
public:
	explicit ATestChracter();
public:
	virtual sf::Shape* GetDrawablePart() override;
private:
	sf::CircleShape* CircleShape_;
};