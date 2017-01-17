#include "playstate.h"

#include <iostream>
#include <string>

PlayState::PlayState(sf::RenderWindow &rwindow, int lvlnr)
	: window(rwindow)
{
	std::string pre = "res/levels/level";
	std::string nr = std::to_string(lvlnr);
	std::string suff = ".png";
	level.loadFromTilemap(pre + nr + suff);
	player = new Player(rwindow, sf::Vector2f(300, 400), level.collisionTiles);
}

void PlayState::mousePressed(sf::Event &ev)
{
	player->mousePressed(ev);
}

void PlayState::mouseReleased(sf::Event &ev)
{
	player->mouseReleased(ev);
}

PlayState::~PlayState()
{
	delete player;
}

void PlayState::update(const float &delta)
{
	player->update(delta);
	level.update(delta);
}

void PlayState::draw()
{
	level.draw(window);
	player->draw();
}
