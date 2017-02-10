#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <random>

#include "..\gamestates\gamestatemanager.h"
#include "..\gamestates\menustate.h"
#include "..\gamestates\playstate.h"
#include "..\entities\player.h"
#include "..\menu\Button.h"
#include "..\utils\TimeStep.h"


class Game
{
public:
	Game();

	void setFullscreen(bool fullscreenb);
	void setFrameRate();

private:
	void setUp();
	void update(TimeStep &timestep);
	void draw();
	void tick();

	bool fullscreen;
	bool running = false;
	int currentlevel = 1;
	int drawtime = 0;
	unsigned int framespersecond;
	unsigned int updatespersecond;

	sf::RenderWindow window;
	sf::View view;
	sf::Color clearcolor;
	sf::Texture currentLevelTileMap;

	sf::Vector2f defaultViewCenter;
	sf::Clock clock;
	sf::Clock drawTime;

	GameStateManager gsm;
	MenuState mainMenu;
	PlayState *playstate;
	
};