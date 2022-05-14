#pragma once
#include "Objects/Actor/Actor.h"
#include "Objects/Controller/Controller.h"
#include "Objects/ActorComponent/InputComponent.h"

class APawn : public AActor
{
public:
	template<class T>
	T* GetController() const;
public:
	virtual void SetupInputComponent(SInputComponent* InputComponent);
	virtual void BeginStart() override;
};

template<class T>
inline T* APawn::GetController() const
{
	return Cast<AController>(Owner_);
}
