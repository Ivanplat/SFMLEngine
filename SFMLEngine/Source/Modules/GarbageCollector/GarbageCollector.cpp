#include "pch.h"
#include "GarbageCollector.h"
#include "Modules/Window/Window.h"

GarbageCollector::~GarbageCollector() noexcept
{
	for (auto i : Modules_)
	{
		if (i)
		{
			delete i;
		}
	}
}

GarbageCollector* GarbageCollector::Instance()
{
	static GarbageCollector GC;
	return &GC;
}

void GarbageCollector::Startup()
{
	auto Wnd = NewModule<Window>();
	Wnd->StartupModule();
}

void GarbageCollector::Shutdown()
{
	for (auto i : Modules_)
	{
		if (i)
		{
			i->ShutdownModule();
		}
	}
}
