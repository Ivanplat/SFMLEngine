#include "pch.h"
#include "Engine.h"
#include "Core/MinimalCore.h"
#include "Modules/Window/Window.h"
#include <thread>
#include "Objects/Character/Character.h"
#include "Objects/Controller/Controller.h"

AMode* SEngine::CurrentMode_ = nullptr;
APawn* SEngine::CurrentPawn_ = nullptr;
AController* SEngine::CurrentController_ = nullptr;


void SEngine::StartupEngine()
{
	if (CurrentMode_)
	{
		std::cout << "GAMEMODE";
		if (auto Controller = SpawnActor<AController>(CurrentMode_->ControllerClass))
		{
			CurrentController_ = Controller;
		}
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

AMode* SEngine::GetCurrentMode() const
{
	return CurrentMode_;
}

AController* SEngine::GetCurrentController() const
{
	return CurrentController_;
}

void SEngine::HandleKeyEvent(sf::Keyboard::Key key)
{
	switch (key)
	{
	case sf::Keyboard::W: 
	{
		CurrentController_->GetInputComponent()->HandleKeyEvent(key);
	}
	break;
	default:
		break;
	}
}

const bool SEngine::IsCharacterInitialized() const
{
	return CurrentPawn_ ? true : false;
}

void SEngine::SetCurrentPawn(APawn* NewPawn)
{
	CurrentPawn_ = NewPawn;
}
