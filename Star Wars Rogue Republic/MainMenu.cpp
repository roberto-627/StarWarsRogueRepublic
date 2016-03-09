#include <SFML/Graphics.hpp>
#include "MainMenu.h"


void movimiento(sf::CircleShape *shape) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		shape->move(-1, 0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		shape->move(0, 1);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		shape->move(1, 0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		shape->move(0, -1);
	}

}

MainMenu::MainMenu()
{
	sf::RenderWindow window(sf::VideoMode(1080, 720), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	sf::Texture image;
	image.loadFromFile("Camisa Daft Punk.png");

	sf::Sprite sprite;
	sprite.setTexture(image);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

		}

		window.clear();
		window.draw(sprite);
		window.draw(shape);
		window.display();
	}
}


MainMenu::~MainMenu()
{
}
