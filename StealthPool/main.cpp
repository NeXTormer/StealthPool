#include <iostream>
#include <SFML/Graphics.hpp>
#include <random>

#include "src\utils\utils.h"
#include "src\gamestates\gamestatemanager.h"
#include "src\gamestates\menustate.h"
#include "src\gamestates\playstate.h"
#include "src\entities\player.h"


int main() {

	//Create Window
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
	
	sf::RectangleShape testshape;
	testshape.setPosition(200, 200);
	testshape.setSize(sf::Vector2f(16, 16));


	Player player(window, sf::Vector2f(200, 200));
	GameStateManager gsm;
	PlayState playstate(1);

	while (window.isOpen()) {
		//Window and Mouseevents
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
			case sf::Event::MouseButtonPressed:
				//TODO: handle player input
				break;
			case sf::Event::MouseButtonReleased:

				break;
			}
		}
		window.clear(clearcolor);

		//move camera
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) view.move(sf::Vector2f(-10, 0));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) view.move(sf::Vector2f(10, 0));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) view.move(sf::Vector2f(0, 10));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) view.move(sf::Vector2f(0, -10));
		window.setView(view);
		//update & render
		player.update(10);
		player.draw();

		playstate.draw(window);
		window.draw(testshape);
		window.display();

		//fps calculation
		time = clock.getElapsedTime();
		//std::cout << 1.0f / time.asSeconds() << std::endl;

		clock.restart().asSeconds();
	}

	window.close();
	

}