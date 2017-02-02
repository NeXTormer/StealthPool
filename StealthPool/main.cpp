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
	
	sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "StealthPool", sf::Style::Fullscreen);
	sf::View view(sf::Vector2f(500, 500), sf::Vector2f(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height));
	window.setFramerateLimit(100);
#else

	sf::RenderWindow window(sf::VideoMode(1920/2, 1080/2), "StealthPool", sf::Style::Close | sf::Style::Default);
	window.setFramerateLimit(100);
	sf::View view(sf::Vector2f(500, 500), sf::Vector2f(1920/2, 1080/2));
	
#endif


	sf::Color clearcolor(0x03030300);
	sf::Vector2f viewcenterbase = view.getCenter();
	int currentlevel = 1;
	sf::Texture levelTileMap;

	GameStateManager gsm;
	PlayState *playstate = new PlayState(window, currentlevel);


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

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) 
		{
			delete playstate;
			currentlevel = 1;
			playstate = new PlayState(window, currentlevel);
			view.setCenter(viewcenterbase);
		}
		
		window.setView(view);
#endif
		//update & render
		playstate->draw();
		if (playstate->update(10, view))
		{
			std::string pre = "res/levels/level";
			std::string lvlnr = std::to_string(currentlevel + 1);
			std::string suff = ".png";
			if (levelTileMap.loadFromFile(pre + lvlnr + suff))
			{
				currentlevel++;
			}
			else
			{
				currentlevel = 1;
			}			
			delete playstate;
			playstate = new PlayState(window, currentlevel);
			
		}
		window.display();
	}

	window.close();
}  