#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Modules/GarbageCollector/GarbageCollector.h"


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
		return t;
	}
	else
	{
		ActorClassToSpawn.Destruct();
		return nullptr;
	}
}