#include "game.h"

Game::Game()
	: window(sf::VideoMode(1536, 864), "StealthPool", sf::Style::Close | sf::Style::Default), clearcolor(0x03030300),
	defaultViewCenter(500, 500), view(defaultViewCenter, sf::Vector2f(1920 / 2, 1080 / 2)), mainMenu(window, gsm)
{
	running = true;
	window.setFramerateLimit(100);
	playstate = new PlayState(window, currentlevel);



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
		{
			drawTime.restart();
			draw();
			frames++;
			drawtime = drawTime.getElapsedTime().asMilliseconds();
		}
		window.display();
		if (clock.getElapsedTime().asMilliseconds() -timer > 1.0f)
		{
			timer += 1.0f;
			framespersecond = frames;
			updatespersecond = updates;
			frames = 0;
			updates = 0;
			tick();
		}

		//Window and Mouseevents
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
				playstate->mousePressed(ev);
				break;
			case sf::Event::MouseButtonReleased:
				playstate->mouseReleased(ev);
				break;
			}
		}
	}

}

void Game::update(float delta)
{

}

void Game::draw()
{

}