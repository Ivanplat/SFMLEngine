#pragma once
#include "Objects/Object/Object.h"
#include "Objects/Class/TSubclassOf.h"
#include <SFML/Graphics.hpp>


struct FActorSpawnParams
{
	SObject* Owner = nullptr;
	sf::Vector2f Position = sf::Vector2f(0.0f, 0.0f);
	sf::Color Color = sf::Color();
	float Size = 0.0f;
};


class AActor : public SObject
{
public:
	explicit AActor() noexcept;
	virtual ~AActor() noexcept {};
public:
	virtual sf::Shape* GetDrawablePart();
	virtual void Initialize();
	sf::Vector2f& GetActorForwardVector();
	sf::Vector2f& GetActorRightVector();
public:
	virtual void SetOwner(SObject* NewOwner);
	virtual SObject* GetOwner() const;
protected:
	SObject* Owner_;
	sf::Vector2f Position_ = sf::Vector2f(0.0f, 0.0f);
	sf::Color Color_ = sf::Color();
	float Size_ = 0.0f;
private:
	sf::Vector2f ForwardVector_;
	sf::Vector2f RightVector_;
public:
	template<class T, class B>
	friend T* SpawnActor(TSubclassOf<B> ActorClassToSpawn, const FActorSpawnParams& SpawnParams);
};