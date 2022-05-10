#pragma once

class AMode;

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
	AMode* GetCurrentMode();
private:
	AMode* CurrentMode_;
};