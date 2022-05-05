#include "pch.h"
#include "Modules/Window/Window.h"
#include "Modules/GarbageCollector/GarbageCollector.h"

int main()
{
	try
	{
		GarbageCollector::Instance();
		GC->Startup();
		//trd.join();
		while (true)
		{
			char ch;
			std::cin >> ch;
			if (ch == '1')
			{
				if (auto window = GC->GetModule<Window>())
				{
					auto shp = window->NewShape<sf::CircleShape>();
					shp->setFillColor(sf::Color::Green);
					shp->setRadius(10.0f);
				}
			}
			if (ch == '0')
			{
				break;
			}
		}
		GC->Shutdown();
		return 0;
	}
	catch (std::exception& e)
	{
		std::cout << e.what();
		return 0;
	}
}
