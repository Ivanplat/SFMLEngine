#include "pch.h"

#include "InputComponent.h"

ActionContainer SInputComponent::ActionEvents_ = ActionContainer();
std::list<IDelegateVoid*> SInputComponent::AxisEvents_ = std::list<IDelegateVoid*>();

int FindActionElement(ActionContainer& v, sf::Keyboard::Key Value)
{
	for (auto i = 0; i < v.size(); i++)
	{	
		if (std::get<0>(v[i]) == Value)
		{
			return i;
		}
	}
	return -1;
}

AxisContainer::iterator* FindAxisElement(AxisContainer::iterator begin, AxisContainer::iterator end, sf::Keyboard::Key Value)
{
	for (auto it = begin; it != end; it++)
	{
		if (std::get<0>(*(it)) == Value)
		{
			return &it;
		}
	}
	return &end;
}



SInputComponent::SInputComponent()
{
}

SInputComponent::~SInputComponent()
{
}

void SInputComponent::HandleKeyEvent(sf::Keyboard::Key Key)
{
	auto it1 = FindActionElement(ActionEvents_, Key);
	/*auto it2 = FindAxisElement(AxisEvents_.begin(), AxisEvents_.end(), Key);*/
	if (it1 != -1)
	{
		auto key = std::get<0>(ActionEvents_[it1]);
		auto ev = std::get<1>(ActionEvents_[it1]);
		auto obj = std::get<2>(ActionEvents_[it1]);
		auto name = std::get<3>(ActionEvents_[it1]);
		if (auto d = obj->FindDelegate(name))
		{
			d->Invoke();
		}
	}
}
