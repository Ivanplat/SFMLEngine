#pragma once

#include "Objects/Actor/Actor.h"


class AMode : public AActor
{
public:
	explicit AMode();
	virtual ~AMode();
public:
	virtual void BeginStart() override;
};
