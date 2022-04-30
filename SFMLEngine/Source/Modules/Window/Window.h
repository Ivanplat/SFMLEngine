#pragma once
#include "pch.h"
#include "Modules/BaseModule.h"

class Window : public IBaseModule
{
public:
	explicit Window() noexcept {}
	virtual ~Window() noexcept;
public:
	virtual void StartupModule() override {}
	virtual void ShutdownModule() override {}
public:
	template<class T>
	T* NewShape();
private:
	std::vector<sf::Shape*> Shapes_;
};

template<class T>
T* Window::NewShape()
{
	auto obj = new T();
	if (dynamic_cast<sf::Shape*>(obj))
	{
		Shapes_.push_back(dynamic_cast<sf::Shape*>(obj));
		return obj;
	}
	delete obj;
	return nullptr;
}
