#include "pch.h"
#include "Window.h"

Window::~Window() noexcept
{
	if (window)
	{
		delete window;
	}
	if (MainThread_)
	{
		delete MainThread_;
	}
	for (auto i : Shapes_)
	{
		if (i)
		{
			delete i;
		}
	}
}

void Window::StartupModule()
{
	MainLoop();
}

void Window::ShutdownModule()
{
	GC->DestroyModule(this);
}

void Window::MainLoop()
{
	MainThread_ = new std::thread([&]()
	{
			static std::mutex mtx;
			mtx.lock();
			window = new sf::RenderWindow(sf::VideoMode(620, 480), "Hello");
			while (window->isOpen())
			{
				if (window)
				{
					sf::Event e;
					if (window->pollEvent(e))
					{
						if (e.type == sf::Event::Closed)
						{
							break;
						}
					}
					window->clear();
					for (auto i : Shapes_)
					{
						if (i)
						{
							window->draw(*i);
						}
					}
					window->display();
				}
			}
			mtx.unlock();
	});
	MainThread_->detach();
}
