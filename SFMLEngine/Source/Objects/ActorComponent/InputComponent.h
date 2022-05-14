#pragma once

#include "ActorComponent.h"
#include <SFML/Graphics.hpp>
#include <functional>
#include <map>
#include <vector>
#include <tuple>


enum class EKeyEventType
{
	Pressed,
	Released
};

typedef std::tuple<sf::Keyboard::Key, EKeyEventType, SObject*, std::string> ActionContainerElement;
typedef std::tuple<sf::Keyboard::Key, SObject*, std::string> AxisContainerElement;
typedef std::vector <ActionContainerElement> ActionContainer;
typedef std::vector<AxisContainerElement> AxisContainer;

class SInputComponent : public SActorComponent
{
public:
	explicit SInputComponent();
	virtual ~SInputComponent();
public:
	template<class ObjectClass>
	void BindActionEvent(sf::Keyboard::Key Key, ObjectClass* Object, std::string EventName, EKeyEventType KeyEventType, void(ObjectClass::*Event)(void));
	template<class ObjectClass>
	void BindAxisEvent(sf::Keyboard::Key Key, ObjectClass* Object, std::string EventName, void(ObjectClass::*Event)(float));
public:
	void HandleKeyEvent(sf::Keyboard::Key Key);
private:
	static ActionContainer  ActionEvents_;
	static std::list<IDelegateVoid*> AxisEvents_;
};



template<class ObjectClass>
void SInputComponent::BindActionEvent(sf::Keyboard::Key Key, ObjectClass* Object, std::string EventName, EKeyEventType KeyEventType, void(ObjectClass::*Event)(void))
{
	if (auto CastedObject = dynamic_cast<SObject*>(Object))
	{
		auto del = NewDelegate<ObjectClass>(Object, Event, EventName);
		CastedObject->AddDelegate(del);
		ActionEvents_.push_back(std::make_tuple(Key, KeyEventType, CastedObject, EventName));
	}
}

template<class ObjectClass>
void SInputComponent::BindAxisEvent(sf::Keyboard::Key Key, ObjectClass* Object, std::string EventName, void(ObjectClass::*Event)(float))
{
	/*if (Object)
	{
		SAxisDelegate<> Delegate;
		Delegate.BindDelegate(Event, EventName);
		if (auto dc = dynamic_cast<SDelegate<void, void>*>(&Delegate))
		{
			Object->AddDelegate(*dc);
			AxisEvents_.push_back(std::make_tuple(Key, Object, EventName));
		}
	}*/
}