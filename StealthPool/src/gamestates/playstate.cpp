#include "playstate.h"

#include <iostream>
#include <string>

sf::Vector2f convert_worldspace_to_screenspace(const sf::View &view, sf::Vector2f worldSpaceCoordinates)
{
	int diffx = view.getCenter().x - view.getSize().x * 0.5f;
	int diffy = view.getCenter().y - view.getSize().y * 0.5f;
	return sf::Vector2f(worldSpaceCoordinates.x - diffx, worldSpaceCoordinates.y - diffy);
}


PlayState::PlayState(sf::RenderWindow &rwindow, int lvlnr)
	: window(rwindow)
{
	std::string pre = "res/levels/level";
	std::string nr = std::to_string(lvlnr);
	std::string suff = ".png";
	level.loadFromTilemap(pre + nr + suff);
	player = new Player(rwindow, sf::Vector2f(300, 400), level.collisionTiles, level.guards);
	staticshader.loadFromFile("res/shader/staticshader.vert", "res/shader/staticshader.frag");

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
	staticshader.setUniform("playerPosition", convert_worldspace_to_screenspace(window.getView(), player->position));
	level.update(delta);
}

void PlayState::draw()
{
	level.draw(window, staticshader);
	player->draw(staticshader);
}
