#include "pch.h"
#include "Engine.h"
#include "Core/MinimalCore.h"
#include "Modules/Window/Window.h"
#include <thread>

void SEngine::StartupEngine()
{
	if (CurrentMode_)
	{
		std::cout << "GAMEMODE";
		CurrentMode_->BeginStart();
	}
	else
	{
		std::cout << "NO GAMEMODE!";
	}
	MainLoop();
	ShutdownEngine();
}

void SEngine::MainLoop()
{
	try
	{
		GarbageCollector::Instance();
		GC->Startup();
		while (true)
		{
			char ch;
			std::cin >> ch;
			if (ch == '1')
			{
				if (auto window = GC->GetModule<Window>())
				{
				}
			}
			if (ch == '0')
			{
				break;
			}
		}
		GC->Shutdown();
		return;
	}
	catch (std::exception& e)
	{
		std::cout << e.what();
		return;
	}
}

void SEngine::ShutdownEngine()
{
	GC->Shutdown();
}

void SEngine::SetMode(AMode* NewMode)
{
	CurrentMode_ = NewMode;
}

AMode* SEngine::GetCurrentMode()
{
	return CurrentMode_;
}
