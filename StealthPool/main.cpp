#include <iostream>
#include <SFML/Graphics.hpp>
#include <random>

#include "src\gamestates\gamestatemanager.h"
#include "src\gamestates\menustate.h"
#include "src\gamestates\playstate.h"
#include "src\entities\player.h"


int main()
{

	//Create Window
#if 0
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "StealthPool", sf::Style::Fullscreen);
	sf::View view(sf::Vector2f(500, 500), sf::Vector2f(1920, 1080));

#else
	sf::RenderWindow window(sf::VideoMode(1920 / 2, 1080 / 2), "StealthPool", sf::Style::Close | sf::Style::Default);
	window.setFramerateLimit(100);
	sf::View view(sf::Vector2f(500, 500), sf::Vector2f(1920 / 2, 1080 / 2));
	
#endif


	sf::Color clearcolor(0x03030300);
	sf::Vector2f viewcenterbase = view.getCenter();
	int currentlevel = 1;

	GameStateManager gsm;
	PlayState *playstate = new PlayState(window, currentlevel);


	sf::CircleShape shape(100);


	while (window.isOpen()) {

		//Window and Mouseevents
		sf::Event ev;
		while (window.pollEvent(ev)) {
			switch (ev.type) {
			case sf::Event::Closed:
				window.close();
				delete playstate;
				return 0;
				break;
			case sf::Event::Resized:
				printf("width: %i, height %i \n", ev.size.width, ev.size.height);
				
				window.setSize(sf::Vector2u(ev.size.width, ev.size.height));
				break;
			case sf::Event::MouseButtonPressed:
				playstate->mousePressed(ev);
				break;
			case sf::Event::MouseButtonReleased:
				playstate->mouseReleased(ev);
				break;
			}
		}
		window.clear(clearcolor);

#if 1
		//move camera
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) view.move(sf::Vector2f(-10, 0));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) view.move(sf::Vector2f(10, 0));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) view.move(sf::Vector2f(0, 10));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) view.move(sf::Vector2f(0, -10));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) 
		{
			//delete playstate; //if it doesn't get deleted it causes a memory leak, can't delete it because bug in >delete[] tiles< in Level::~Level()
			currentlevel = 1;
			playstate = new PlayState(window, currentlevel);
			view.setCenter(viewcenterbase);
		}
		
		window.setView(view);
#endif
		//update & render
		playstate->draw();
		if (playstate->update(10))
		{
			currentlevel++;
			// delete playstate; should be deleted but doest't work
			playstate = new PlayState(window, currentlevel);
			view.setCenter(viewcenterbase);
		}
		window.display();
	}

	window.close();


	

}  