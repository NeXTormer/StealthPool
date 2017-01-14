#include <iostream>
#include <SFML/Graphics.hpp>
#include <random>

#include "src\utils\utils.h"
#include "src\gamestates\gamestatemanager.h"
#include "src\gamestates\menustate.h"



int main() {


#if 0
	sf::RenderWindow window(sf::VideoMode(2560, 1440), "Peter", sf::Style::Fullscreen);
	sf::View view(sf::Vector2f(2560 / 2, 1440 / 2), sf::Vector2f(2560, 1440));

#else
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Peter", sf::Style::Close | sf::Style::Default);
	window.setFramerateLimit(100);
	sf::View view(sf::Vector2f(500, 500), sf::Vector2f(1000, 1000));
	
#endif
	sf::Color clearcolor(0x3A40f5);
	sf::Clock clock;
	sf::Time time;
	sf::CircleShape shape(50);

	shape.setPosition(sf::Vector2f(100, 100));

	GameStateManager gsm;
	MenuState menustate(gsm);


	while (window.isOpen()) {
		window.clear(clearcolor);
		
		menustate.update(0.01);
		menustate.draw(window);


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) view.move(sf::Vector2f(-10, 0));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) view.move(sf::Vector2f(10, 0));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) view.move(sf::Vector2f(0, 10));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) view.move(sf::Vector2f(0, -10));
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) view.zoom(1.1);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) view.zoom(0.9);
		window.setView(view);
		

		sf::Event ev;
		while (window.pollEvent(ev)) {
			switch (ev.type) {
			case sf::Event::Closed:
				window.close();
				return 0;
				break;
			case sf::Event::Resized:
				printf("width: %i, height %i \n", ev.size.width, ev.size.height);
				
				window.setSize(sf::Vector2u(ev.size.width, ev.size.height));
				break;
			case sf::Event::TextEntered:
				printf("%c", ev.text.unicode);
			}
		}
		window.display();

		time = clock.getElapsedTime();
		//std::cout << 1.0f / time.asSeconds() << std::endl;

		clock.restart().asSeconds();
	}

	window.close();
	

}