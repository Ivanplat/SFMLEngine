#include "pch.h"
#include "Modules/Window/Window.h"

int main()
{
	sf::RenderWindow rw(sf::VideoMode(640, 420), "HELLO");

	Window wnd;
	auto crs = wnd.NewShape<sf::CircleShape>();

	while (rw.isOpen())
	{
		sf::Event e;
		sf::CircleShape cs;
		cs.setFillColor(sf::Color::Red);
		cs.setRadius(5.0f);
		while (rw.pollEvent(e))
		{
			if (e.type != sf::Event::Closed)
			{
				rw.clear();
				rw.draw(cs);
				rw.display();
			}
			
		}
	}

	return 0;
}
