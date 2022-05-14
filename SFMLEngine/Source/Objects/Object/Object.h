#pragma once

#include "Objects/RawObject/RawObject.h"
#include "Objects/Delegates/Delegate.h"

class SObject : virtual public SRawObject
{
public:
	explicit SObject() noexcept {};
	virtual ~SObject() noexcept {};
public:
	virtual void BeginStart();
	virtual void Tick();
	bool IsDrawable() const;
	void SetTickEnabled(const bool NewState);
protected:
	static void SuperTick(SObject* self);
protected:
	bool IsDrawable_ = false;
	bool TickEnabled_ = true;
public:
	void AddDelegate(IDelegateVoid* Delegate);
	IDelegateVoid* FindDelegate(std::string FunctionName);
protected:
	std::vector<IDelegateVoid*> Delegates;
};

template<class T>
T* NewObject()
{
	auto t = new T();
	if (auto tc = Cast<SObject>(t))
	{
		return dynamic_cast<T*>(tc);
	}
	delete t;
	return nullptr;
}