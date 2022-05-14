#pragma once

#include "Objects/Class/Class.h"
#include <functional>
#include <vector>

class SRawObject : virtual public SClass
{
public:
	explicit SRawObject() noexcept {};
	virtual ~SRawObject() noexcept {};
public:
	std::vector<std::function<void()>> BindedEvents;
	void RunBinedFunction(std::function<void()>& F);
};