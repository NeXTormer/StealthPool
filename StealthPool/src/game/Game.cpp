#include "game.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <random>

#include "..\gamestates\gamestatemanager.h"
#include "..\gamestates\menustate.h"
#include "..\gamestates\playstate.h"
#include "..\entities\player.h"
#include "..\menu\Button.h"

Game::Game()
	: window(sf::VideoMode(1536, 864), "StealthPool", sf::Style::Close | sf::Style::Default), clearcolor(0x03030300),
	defaultViewCenter(500, 500), view(defaultViewCenter, sf::Vector2f(1920 / 1, 1080 / 1)), mainMenu(window, gsm)
{
	running = true;
	//window.setFramerateLimit(100);
	playstate = new PlayState(window, currentlevel);

	setUp();

}

void Game::setFullscreen(bool fs)
{

}

void Game::setUp()
{

	clock.restart();
	float timer = 0.0f;
	float updateTimer = clock.getElapsedTime().asMilliseconds();
	float updateTick = 1000.0f / 60.0f;
	unsigned int frames = 0;
	unsigned int updates = 0;
	TimeStep timestep(clock.getElapsedTime().asMilliseconds());

	while (running)
	{
		window.clear(clearcolor);
		float now = clock.getElapsedTime().asMilliseconds();
		if (now - updateTimer > updateTick)
		{
			timestep.Update(now);
			update(timestep);
			updates++;
			updateTimer += updateTick;
		}
		
		drawTime.restart();
		draw();
		frames++;
		drawtime = drawTime.getElapsedTime().asMilliseconds();
		
		if (clock.getElapsedTime().asMilliseconds() - timer > 1000.0f)
		{
			timer += 1000.0f;
			framespersecond = frames;
			updatespersecond = updates;
			frames = 0;
			updates = 0;
			tick();
			printf("%d fps, %d ups\n", framespersecond, updatespersecond);
		}

		sf::Event ev;
		while (window.pollEvent(ev)) {
			switch (ev.type) {
			case sf::Event::Closed:
				window.close();
				delete playstate;
				running = false;
				break;
			case sf::Event::Resized:
				printf("width: %i, height %i \n", ev.size.width, ev.size.height);

				window.setSize(sf::Vector2u(ev.size.width, ev.size.height));
				break;
			case sf::Event::MouseButtonPressed:
				mousePressed(ev);
				break;
			case sf::Event::MouseButtonReleased:
				mouseReleased(ev);
				break;
			}
		}
	}

}

void Game::update(TimeStep &timestep)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		delete playstate;
		currentlevel = 1;
		playstate = new PlayState(window, currentlevel);
		view.setCenter(defaultViewCenter);
	}

	window.setView(view);

	if (playstate->update(10, view))
	{
		std::string pre = "res/levels/level";
		std::string lvlnr = std::to_string(currentlevel + 1);
		std::string suff = ".png";
		if (currentLevelTileMap.loadFromFile(pre + lvlnr + suff))
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
}

void Game::draw()
{
	playstate->draw();
	window.display();
}

void Game::tick()
{

}

void Game::mousePressed(sf::Event &ev)
{
	playstate->mousePressed(ev);
}

void Game::mouseReleased(sf::Event &ev)
{
	playstate->mouseReleased(ev);
}