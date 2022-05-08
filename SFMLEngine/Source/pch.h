#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Modules/GarbageCollector/GarbageCollector.h"
#include "Modules/Logger/Logger.h"


static auto* GC = GarbageCollector::Instance();


template<class T, class B>
T* SpawnActor(TSubclassOf<B> ActorClassToSpawn)
{
	if (!dynamic_cast<T*>(ActorClassToSpawn.GetClass()))
	{
		ActorClassToSpawn.Destruct();
		return nullptr;
	}
	AActor* cst = Cast<AActor>(dynamic_cast<SClass*>(ActorClassToSpawn.GetClass()));
	if (cst)
	{
		auto t = new T();
		GC->AddActor(dynamic_cast<AActor*>(t));
		dynamic_cast<AActor*>(t)->BeginStart();
		return t;
	}
	else
	{
		ActorClassToSpawn.Destruct();
		return nullptr;
	}
}

template<class T, class B>
T* SpawnActor(TSubclassOf<B> ActorClassToSpawn, const FActorSpawnParams& SpawnParams)
{
	if (auto Actor = SpawnActor<T>(ActorClassToSpawn))
	{
		Actor->Owner_ = SpawnParams.Owner;
		Actor->Position_ = SpawnParams.Position;
		Actor->Color_ = SpawnParams.Color;
		Actor->Size_ = SpawnParams.Size;
		return Actor;
	}
	return nullptr;
}
