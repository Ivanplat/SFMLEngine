#pragma once

#include "MinimalCore.h"


class AMode : public AActor
{
public:
	explicit AMode();
	virtual ~AMode();
public:
	virtual void BeginStart() override;
public:
	TSubclassOf<class AController> ControllerClass;
	TSubclassOf<class ACharacter> CharacterClass;
};
