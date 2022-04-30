#pragma once

class IBaseModule
{
public:
	virtual void StartupModule() = 0;
	virtual void ShutdownModule() = 0;
};