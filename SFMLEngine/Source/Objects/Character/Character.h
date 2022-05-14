#pragma once
#include "Objects/Pawn/Pawn.h"

class ACharacter : public APawn
{
public:
	explicit ACharacter();
public:
	virtual void BeginStart() override;
};