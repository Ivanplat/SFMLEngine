#include "pch.h"
#include "Window.h"
#include <random>

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
	if(window)
	{
		window->close();
	}
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
							GC->DestroyModule(this);
							break;
						}
					}
					if (e.type == sf::Event::KeyPressed)
					{
						Engine->HandleKeyEvent(e.key.code);
					}
					window->clear();
					for (auto i : *GC->GetActors())
					{
						if (i)
						{
							if (auto dp = i->GetDrawablePart())
							{
								window->draw(*dp);
							}
						}
					}
					window->display();
					RandomMove();
				}
			}
			mtx.unlock();
	});
	MainThread_->detach();
}

void Window::RandomMove()
{
	for (auto i : Shapes_)
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::mt19937 gen2(rd());
		std::uniform_real_distribution<> dist(-1.0f, 1.0f);
		std::uniform_real_distribution<> dist2(-1.0f, 1.0f);
		i->setPosition(i->getPosition() + sf::Vector2f(dist(gen), dist2(gen2)));
	}
}

sf::Shape* Window::GetTailShape()
{
	if (Shapes_.size() > 0)
	{
		return Shapes_[Shapes_.size() - 1];
	}
	return nullptr;
}
