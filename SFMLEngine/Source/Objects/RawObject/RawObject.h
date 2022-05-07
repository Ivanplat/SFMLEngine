#pragma once

#include "Objects/Class/Class.h"

class SRawObject : virtual public SClass
{
public:
	explicit SRawObject() noexcept {};
	virtual ~SRawObject() noexcept {};
};