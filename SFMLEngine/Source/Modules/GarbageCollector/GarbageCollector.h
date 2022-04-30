#pragma once
#include "pch.h"
#include "Modules/BaseModule.h"

class GarbageCollector : public IBaseModule
{
public:
	explicit GarbageCollector() noexcept {}
	virtual ~GarbageCollector() noexcept {}
public:
	virtual void StartupModule() override {}
	virtual void ShutdownModule() override {}
};