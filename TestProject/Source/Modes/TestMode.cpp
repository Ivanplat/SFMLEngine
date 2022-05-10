#include "pch.h"
#include "TestMode.h"
#include "Actors/TestActor.h"
#include "Characters/TestCharacter.h"

ATestMode::ATestMode()
{
	SetClassName();
}

void ATestMode::BeginStart()
{
	TSubclassOf<ATestChracter> TestActorClass;
	FActorSpawnParams Params;
	Params.Color = sf::Color::Blue;
	Params.Owner = nullptr;
	Params.Position = sf::Vector2f(10, 10);
	Params.Size = 10;
	auto p = SpawnActor<ATestChracter>(TestActorClass, Params);
	auto c = Engine->GetCurrentController();
	c->Posses(Cast<APawn>(p));
}
