#include "playstate.h"

#include <iostream>
#include <string>

PlayState::PlayState(const int lvlnr)
{
	std::string pre = "res/levels/level";
	std::string nr = std::to_string(lvlnr);
	std::string suff = ".png";
	level.loadFromTilemap(pre + nr + suff);
}

PlayState::~PlayState()
{

}

void PlayState::update(const float & delta)
{

}

void PlayState::draw(sf::RenderWindow & window)
{
	level.draw(window);
}
