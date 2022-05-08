#include "pch.h"
#include "Modules/Window/Window.h"
#include "Modules/GarbageCollector/GarbageCollector.h"
#include <random>
#include "Objects/Class/TSubclassOf.h"
#include "Objects/Actor/Actor.h"
#include "Actors/TestActor.h"


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
				TSubclassOf<ATestActor> aClass;
				FActorSpawnParams Params;
				Params.Size = 20.0f;
				Params.Position = sf::Vector2f(100.0f, 100.0f);
				Params.Color = sf::Color::Blue;
				auto nActor = SpawnActor<ATestActor>(aClass, Params);
				if (auto window = GC->GetModule<Window>())
				{
					/*for (int j = 0; j < 100; j++)
					{
						auto shp = window->NewShape<sf::CircleShape>();
						std::random_device rd;
						std::mt19937 gen(rd());
						std::mt19937 gen2(rd());
						std::mt19937 gen3(rd());
						std::uniform_real_distribution<> dist(0.0f, 600.0f);
						std::uniform_real_distribution<> dist2(0.0f, 600.0f);
						std::uniform_int_distribution<> dist3(0, 4);
						auto color = sf::Color::Red;
						auto i = dist3(gen3);
						switch (i)
						{
						case 0: color = sf::Color::Blue; break;
						case 1: color = sf::Color::Green; break;
						case 2: color = sf::Color::Yellow; break;
						}
						shp->setFillColor(color);
						shp->setRadius(10.0f);
						shp->setPosition(sf::Vector2f(dist(gen), dist2(gen2)));
					}*/
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
