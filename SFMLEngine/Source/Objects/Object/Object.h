#pragma once

#include "Objects/RawObject/RawObject.h"

class SObject : virtual public SRawObject
{
public:
	explicit SObject() noexcept {};
	virtual ~SObject() noexcept {};
public:
	virtual void BeginStart();
	bool IsDrowable() const;
protected:
	bool IsDrowable_ = false;
};