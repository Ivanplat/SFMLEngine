#pragma once

#include "Objects/RawObject/RawObject.h"

class SObject : virtual public SRawObject
{
public:
	explicit SObject() noexcept {};
	virtual ~SObject() noexcept {};
public:
	virtual void BeginStart();
	virtual void Tick();
	bool IsDrowable() const;
	void SetTickEnabled(const bool NewState);
protected:
	static void SuperTick(SObject* self);
protected:
	bool IsDrowable_ = false;
	bool TickEnabled_ = true;
};