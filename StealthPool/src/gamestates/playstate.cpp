#include "playstate.h"

#include <iostream>
#include <string>

PlayState::PlayState(sf::RenderWindow &rwindow, int lvlnr)
	: player(rwindow, level, sf::Vector2f(300, 300)), window(rwindow)
{
	std::string pre = "res/levels/level";
	std::string nr = std::to_string(lvlnr);
	std::string suff = ".png";
	level.loadFromTilemap(pre + nr + suff);
}

void PlayState::mousePressed(sf::Event &ev)
{
	player.mousePressed(ev);
}

void PlayState::mouseReleased(sf::Event &ev)
{
	player.mouseReleased(ev);
}

PlayState::~PlayState()
{

}

void PlayState::update(const float &delta)
{
	player.update(delta);
}

void PlayState::draw()
{
	level.draw(window);
	player.draw();
}
