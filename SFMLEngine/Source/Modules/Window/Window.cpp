#include "pch.h"
#include "Window.h"

Window::~Window() noexcept
{
	for (auto i : Shapes_)
	{
		if (i)
		{
			delete i;
		}
	}
}
