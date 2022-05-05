#pragma once
#include "pch.h"
#include "Modules/BaseModule.h"
#include <thread>
#include <mutex>

class Window : public IBaseModule
{
public:
	explicit Window() noexcept {}
	virtual ~Window() noexcept;
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
private:
	void MainLoop();
public:
	template<class T>
	T* NewShape();
public:
	sf::RenderWindow* window;
private:
	std::vector<sf::Shape*> Shapes_;
	std::thread* MainThread_;
};

template<class T>
T* Window::NewShape()
{
	static std::mutex mtx;
	mtx.lock();
	auto obj = new T();
	if (dynamic_cast<sf::Shape*>(obj))
	{
		Shapes_.push_back(dynamic_cast<sf::Shape*>(obj));
		mtx.unlock();
		return obj;
	}
	delete obj;
	mtx.unlock();
	return nullptr;
}
