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
	auto c = Engine->GetCurrentController();
	Params.Color = sf::Color::Blue;
	Params.Owner = c;
	Params.Position = sf::Vector2f(10, 10);
	Params.Size = 10;
	auto p = SpawnActor<ATestChracter>(TestActorClass, Params);
	c->Posses(Cast<APawn>(p));
}
