#pragma once
#include "Objects/Actor/Actor.h"
#include "Objects/Controller/Controller.h"

class APawn : public AActor
{
public:
	template<class T>
	T* GetController() const;
};

template<class T>
inline T* APawn::GetController() const
{
	return Cast<AController>(Owner_);
}
