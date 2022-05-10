#pragma once

#include <SFML/Graphics.hpp>

#include "Objects/Pawn/Pawn.h"

class AMode;
class ACharacter;
class AController;
class APawn;

class SEngine
{
public:
	explicit SEngine() noexcept = default;
	virtual ~SEngine() noexcept = default;
private:
public:
	void StartupEngine();
	void MainLoop();
	void ShutdownEngine();
	void SetMode(class AMode* NewMode);
	AMode* GetCurrentMode() const;
	AController* GetCurrentController() const;
	void HandleKeyEvent(sf::Keyboard::Key key);
	const bool IsCharacterInitialized() const;
	void SetCurrentPawn(APawn* NewPawn);
private:
	static AMode* CurrentMode_;
	static APawn* CurrentPawn_;
	static AController* CurrentController_;
};