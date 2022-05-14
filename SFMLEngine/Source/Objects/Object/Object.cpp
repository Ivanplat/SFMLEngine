#include "pch.h"
#include "Object.h"
#include <future>

void SObject::BeginStart()
{
	std::string msg("BEGIN");
	LG->PrintLog(msg);
	if (TickEnabled_)
	{
		auto ST = std::async(&SObject::SuperTick, this);
		ST.wait_for(std::chrono::milliseconds(10));
	}
}

void SObject::Tick()
{

}

bool SObject::IsDrawable() const
{
	return IsDrawable_;
}

void SObject::SetTickEnabled(const bool NewState)
{
	TickEnabled_ = NewState;
}

void SObject::SuperTick(SObject* self)
{
	self->Tick();
	auto ST = std::async(std::launch::deferred, & SObject::SuperTick, self);
	ST.wait_for(std::chrono::milliseconds(10));
}

void SObject::AddDelegate(IDelegateVoid* Delegate)
{
	Delegates.push_back(Delegate);
}

IDelegateVoid* SObject::FindDelegate(std::string FunctionName)
{
	for (auto i = 0; i < Delegates.size(); i++)
	{
		if (Delegates[i]->DelegateName == FunctionName)
		{
			return Delegates[i];
		}
	}
	return nullptr;
}
